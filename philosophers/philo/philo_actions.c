/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:23:51 by thchau            #+#    #+#             */
/*   Updated: 2025/04/23 15:04:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	calculate_thinking_time_ms(long timestamp, t_philo *philo)
{
	long	relative_elapsed;
	long	last_meal_time;

	last_meal_time = get_long(&philo->mtx, &philo->last_meal_time);
	if (last_meal_time <= -1)
		relative_elapsed = timestamp - philo->table->start_simulation;
	else
		relative_elapsed = timestamp - last_meal_time;
	return (((philo->table->time_to_die / 1e3) - relative_elapsed) / 2);
}

void	philo_thinks(t_philo *philo)
{
	long	time_to_think;
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	time_to_think = calculate_thinking_time_ms(timestamp, philo);
	if (time_to_think > 0)
	{
		if (log_action(THINKING, philo))
			custom_usleep(time_to_think * 1e3);
	}
}

void	philo_sleeps(t_philo *philo)
{
	if (log_action(SLEEPING, philo))
		custom_usleep(philo->table->time_to_sleep);
}

t_error_code	philo_eats(t_philo *philo)
{
	if (safe_mutex_handle(&philo->first_fork->fork, LOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	log_action(TAKE_FIRST_FORK, philo);
	if (safe_mutex_handle(&philo->second_fork->fork, LOCK) == ERROR_MUTEX)
	{
		safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
		return (ERROR_MUTEX);
	}
	log_action(TAKE_SECOND_FORK, philo);
	set_long(&philo->mtx, &philo->last_meal_time, get_time(MILLISECOND));
	philo->num_of_meals++;
	log_action(EATING, philo);
	custom_usleep(philo->table->time_to_eat);
	if (philo->table->nbr_limit_meal > 0
		&& philo->num_of_meals == philo->table->nbr_limit_meal)
		set_bool(&philo->mtx, &philo->is_full, true);
	if (safe_mutex_handle(&philo->second_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	if (safe_mutex_handle(&philo->first_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	return (SUCCESS);
}
