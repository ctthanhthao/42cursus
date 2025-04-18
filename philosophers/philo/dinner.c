/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:00:28 by thchau            #+#    #+#             */
/*   Updated: 2025/04/18 11:10:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void *dinner_simulation(void *data)
{
	t_philo 		*philo;
	t_error_code	status;
		
	philo = (t_philo*) data;
	while (!philo->table->all_threads_ready);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->mtx, &philo->is_full))
			break ;
		status = philo_eats(philo);
		if (status == ERROR_MUTEX)
			return (log_error("Error happens when philo starts to eat."),NULL);
		if (status == THREAD_DIED)
		{
			set_bool(&philo->table->access_mtx, &philo->table->end_simulation, true);
			log_action(DIED, philo);
			break ;
		}
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	
	return (NULL);
}

void	*start_monitor(void *data)
{
	t_philo *philo;
	t_table	*tb;
	int		i;
	bool	all_full;

	tb = (t_table *)data;
	all_full = true;
	while (!simulation_finished(tb))
	{
		i = 0;
		all_full = true;
		while (i < tb->philo_nbr)
		{
			philo = tb->philos + i;
			if (!get_bool(&philo->mtx, &philo->is_full))
				all_full = false;
			i++;
		}
		usleep(10);
	}
	if (all_full)
		set_bool(&tb->access_mtx, &tb->end_simulation, true);
	return (NULL);
}

/*
* 1. will end simulation if all philos are full
*/
static void	monitor_process(void *data)
{
	pthread_t monitor;
	t_table *tb;
	
	tb = (t_table *)data;
	while (!tb->all_threads_ready);
	if (safe_thread_handle(&monitor, 
		&start_monitor, tb, CREATE) == ERROR_THREAD)
	{
		log_message("Failed to start monitor process.");
		return ;
	}
}

static void	*start_alone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("start_alone STARTS\n");
	printf("lock philo %d - philo->first_fork->fork : %p\n", philo->id, (void *)&philo->first_fork->fork);
	if (safe_mutex_handle(&philo->first_fork->fork, LOCK) == ERROR_MUTEX)
	{
		printf("ERROR philo %d - philo->first_fork->fork : %p\n", philo->id, (void *)&philo->first_fork->fork);
		return (NULL);
	}
	log_action(TAKE_FIRST_FORK, philo);
	if (safe_mutex_handle(&philo->first_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (NULL);
	usleep(philo->table->time_to_die * 1e3);
	log_action(DIED, philo);
	set_bool(&philo->table->access_mtx, &philo->table->end_simulation, true);
	return (NULL);
}

static t_error_code one_philo(t_table *tb)
{
	printf("one_philo STARTS\n");
	tb->start_simulation = get_time(MILLISECOND);
	if (safe_thread_handle(&tb->philos[0].thread, 
		&start_alone, &tb->philos[0], CREATE) == ERROR_THREAD)
		return (ERROR_DINNER_START);
	if (safe_thread_handle(&tb->philos[0].thread, NULL, 
		NULL, JOIN) == ERROR_THREAD)
		return (ERROR_DINNER_START);
	return (SUCCESS);
}

/*
* 1. if num of meal = 0, return
* 2. If philo is only one, it will die
* 3. create all threads.
* 4. wait until all threads are created, start a monitor
* which goes to check if any thread dies or all threads are full. -> end simulation 
*/
t_error_code	dinner_start(t_table *tb)
{
	int	i;
	
	i = 0;
	if (tb->nbr_limit_meal == 0)
		return (SUCCESS);
	if (tb->philo_nbr == 1)
		return (one_philo(tb));
	else
	{
		while (i < tb->philo_nbr)
		{
			if (safe_thread_handle(&tb->philos[i].thread, 
				dinner_simulation, &tb->philos[i].thread, CREATE) == ERROR_THREAD)
				return (ERROR_DINNER_START);
			i++;
		}
		tb->start_simulation = get_time(MILLISECOND);
		set_bool(&tb->access_mtx, &tb->all_threads_ready, true);
		monitor_process(tb);
		i = 0;
		while (i < tb->philo_nbr)
		{
			if (safe_thread_handle(&tb->philos[i].thread, NULL, 
				NULL, JOIN) == ERROR_THREAD)
				return (ERROR_DINNER_START);
			i++;
		}
	}
	return (SUCCESS);
}