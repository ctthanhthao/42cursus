/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:23:51 by thchau            #+#    #+#             */
/*   Updated: 2025/04/15 10:27:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	calculate_thinking_time (long timestamp, t_philo *philo)
{
	long	relative_elapsed;

	if (philo->last_meal_time <= -1)
		relative_elapsed = timestamp - philo->table->start_simulation;
	else
		relative_elapsed = timestamp - philo->last_meal_time;
	return (((philo->table->time_to_die / 1e3) - relative_elapsed) / 2);
}

bool	can_eat(t_philo *philo)
{
	long	elapsed_from_last_meal;
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	//printf("philo[%i] timestamp: %ld\n", philo->id, timestamp);
	if (philo->last_meal_time > 0)
		elapsed_from_last_meal = timestamp - philo->last_meal_time;
	else
		elapsed_from_last_meal = timestamp - philo->table->start_simulation;
	//printf("philo[%i] elapsed_from_last_meal: %ld\n", philo->id, elapsed_from_last_meal);
	if (elapsed_from_last_meal < (philo->table->time_to_die / 1e3))
		return (true);
	return (false);
}

void	philo_thinks(t_philo *philo)
{
	long	time_to_think;
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	time_to_think = calculate_thinking_time(timestamp, philo);
	if (time_to_think > 0)
	{
		if(log_action(THINKING, philo))
		{
			custom_usleep(time_to_think);
		}
	}
}

void	philo_sleeps(t_philo *philo)
{
	if(log_action(SLEEPING, philo))
		custom_usleep(philo->table->time_to_sleep);
}

t_error_code	philo_eats(t_philo *philo)
{
	if (!can_eat(philo))
	{
		philo->is_dead = true;
		return (THREAD_DIED);
	}
	if (safe_mutex_handle(&philo->first_fork->fork, LOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	log_action(TAKE_FIRST_FORK, philo);
	if (safe_mutex_handle(&philo->second_fork->fork, LOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	log_action(TAKE_SECOND_FORK, philo);
	log_action(EATING, philo);
	philo->num_of_meals++;
	philo->last_meal_time = get_time(MILLISECOND);
	custom_usleep(philo->table->time_to_eat);
	if (philo->table->nbr_limit_meal > 0 &&
		philo->num_of_meals >= philo->table->nbr_limit_meal)
		set_bool(&philo->mtx, &philo->is_full, true);
	if (safe_mutex_handle(&philo->second_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	if (safe_mutex_handle(&philo->first_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (ERROR_MUTEX);
	return (SUCCESS);
}