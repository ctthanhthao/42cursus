/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/04/27 17:57:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static bool	is_dead(t_philo *philo)
{
	long	elapsed_from_last_meal;
	long	timestamp;
	long	last_meal_time;

	timestamp = get_time(MILLISECOND);
	safe_sem_wait(philo->table->sem_last_meal, "sem_wait last meal");
	last_meal_time = philo->last_meal_time;
	safe_sem_post(philo->table->sem_last_meal, "sem_post last meal");
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

	philo = (t_philo *)data;
	while (1)
	{
		if (is_dead(philo))
		{
			log_action(DIED, philo);
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
	return (NULL);
}

t_error_code	trigger_monitor_death(t_philo *philo)
{
	if (safe_thread_handle(&philo->table->monitor_dead, monitor_philo_dead,
			philo, CREATE) == ERROR_THREAD)
		return (ERROR_DINNER_START);
	if (safe_thread_handle(&philo->table->monitor_dead, NULL, NULL, DETACH)
		== ERROR_THREAD)
		return (ERROR_DINNER_START);
	return (SUCCESS);
}
