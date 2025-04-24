/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 15:08:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_dead(t_philo *philo)
{
	long	elapsed_from_last_meal;
	long	timestamp;
	long	last_meal_time;

	timestamp = get_time(MILLISECOND);
	last_meal_time = get_long(&philo->mtx, &philo->last_meal_time);
	if (last_meal_time > 0)
		elapsed_from_last_meal = timestamp - last_meal_time;
	else
		elapsed_from_last_meal = timestamp - philo->table->start_simulation;
	if (elapsed_from_last_meal < (philo->table->time_to_die / 1e3))
		return (false);
	return (true);
}

static void	*monitor_philo_dead(void *data)
{
	t_philo	*philo;
	t_table	*tb;
	int		i;

	tb = (t_table *)data;
	while (!all_philos_started(tb))
		usleep(50);
	while (!simulation_finished(tb))
	{
		i = 0;
		while (i < tb->philo_nbr)
		{
			philo = tb->philos + i;
			if (is_dead(philo))
			{
				log_action(DIED, philo);
				return (set_bool(&tb->access_mtx, &tb->end_simulation, true),
					NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

/*
* Monitor will check if all philos are full
* If yes, end simulation.
*/
static void	*monitor_philos_full(void *data)
{
	t_philo	*philo;
	t_table	*tb;
	int		i;
	bool	all_full;

	tb = (t_table *)data;
	while (!all_philos_started(tb))
		usleep(50);
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
		if (all_full)
			return (set_bool(&tb->access_mtx, &tb->end_simulation, true), NULL);
		else
			usleep(10);
	}
	return (NULL);
}

t_error_code	trigger_monitor_threads(t_table *tb)
{
	if (safe_thread_handle(&tb->monitor_dead, monitor_philo_dead, tb,
			CREATE) == ERROR_THREAD)
	{
		log_error("Failed to start monitor dead philo process.");
		return (ERROR_DINNER_START);
	}
	if (tb->nbr_limit_meal > 0)
	{
		if (safe_thread_handle(&tb->monitor_full, monitor_philos_full, tb,
				CREATE) == ERROR_THREAD)
		{
			log_error("Failed to start monitor all full philos process.");
			return (ERROR_DINNER_START);
		}
	}
	return (SUCCESS);
}

t_error_code	join_monitor_threads(t_table *tb)
{
	if (safe_thread_handle(&tb->monitor_dead, NULL, NULL,
			JOIN) == ERROR_THREAD)
	{
		log_error("Failed to join monitor dead philo process.");
		return (ERROR_DINNER_START);
	}
	if (tb->nbr_limit_meal > 0)
	{
		if (safe_thread_handle(&tb->monitor_full, NULL, NULL,
				JOIN) == ERROR_THREAD)
		{
			log_error("Failed to join monitor all full philos process.");
			return (ERROR_DINNER_START);
		}
	}
	return (SUCCESS);
}
