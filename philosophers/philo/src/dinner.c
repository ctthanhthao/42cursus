/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:00:28 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 15:03:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*dinner_simulation(void *data)
{
	t_philo			*philo;
	t_error_code	status;

	philo = (t_philo *)data;
	while (!get_bool(&philo->table->access_mtx,
			&philo->table->all_threads_ready))
		usleep(50);
	set_bool(&philo->mtx, &philo->has_started, true);
	while (!simulation_finished(philo->table))
	{
		status = philo_eats(philo);
		if (status == ERROR_MUTEX)
			return (log_error("Error happens when philo starts to eat."), NULL);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
	return (NULL);
}

static t_error_code	trigger_philos_threads(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		if (safe_thread_handle(&tb->philos[i].thread, dinner_simulation,
				&tb->philos[i], CREATE) == ERROR_THREAD)
		{
			log_error("Failed to init philo thread.");
			return (ERROR_DINNER_START);
		}
		i++;
	}
	return (SUCCESS);
}

static t_error_code	join_philos_threads(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		if (safe_thread_handle(&tb->philos[i].thread, NULL,
				NULL, JOIN) == ERROR_THREAD)
		{
			log_error("Failed to join philo thread.");
			return (ERROR_DINNER_START);
		}
		i++;
	}
	return (SUCCESS);
}

/*
* 1. if num of meal = 0, return
* 2. If philo is only one, it will die
* 3. create all threads.
* 4. wait until all threads are created, start a monitor
* which goes to check if any thread dies or all threads are full. 
-> end simulation 
*/
t_error_code	dinner_start(t_table *tb)
{
	if (tb->nbr_limit_meal == 0)
		return (SUCCESS);
	if (tb->philo_nbr == 1)
		return (one_philo(tb));
	else
	{
		if (trigger_philos_threads(tb) == ERROR_DINNER_START)
			return (ERROR_DINNER_START);
		if (trigger_monitor_threads(tb) == ERROR_DINNER_START)
			return (ERROR_DINNER_START);
		tb->start_simulation = get_time(MILLISECOND);
		set_bool(&tb->access_mtx, &tb->all_threads_ready, true);
		if (join_philos_threads(tb) == ERROR_DINNER_START)
			return (ERROR_DINNER_START);
		if (join_monitor_threads(tb) == ERROR_DINNER_START)
			return (ERROR_DINNER_START);
	}
	return (SUCCESS);
}
