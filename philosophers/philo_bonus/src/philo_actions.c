/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:23:51 by thchau            #+#    #+#             */
/*   Updated: 2025/05/01 10:21:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static long	calculate_thinking_time_ms(long timestamp, t_philo *philo)
{
	long	relative_elapsed;
	long	last_meal_time;

	last_meal_time = get_long(philo->table->sem_meal, &philo->last_meal_time);
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
		log_action(THINKING, philo);
		custom_usleep(time_to_think * 1e3);
	}
}

void	philo_sleeps(t_philo *philo)
{
	log_action(SLEEPING, philo);
	custom_usleep(philo->table->time_to_sleep);
}

void	philo_eats(t_philo *philo)
{
	safe_sem_wait(philo->first_fork->sem_fork, "sem_wait first fork");
	log_action(TAKE_FIRST_FORK, philo);
	safe_sem_wait(philo->second_fork->sem_fork, "sem_wait second fork");
	log_action(TAKE_SECOND_FORK, philo);
	safe_sem_wait(philo->table->sem_meal, "sem_wait access meal attr");
	philo->last_meal_time = get_time(MILLISECOND);
	philo->num_of_meals++;
	safe_sem_post(philo->table->sem_meal, "sem_post access meal attr");
	log_action(EATING, philo);
	custom_usleep(philo->table->time_to_eat);
	safe_sem_post(philo->first_fork->sem_fork, "sem_post first fork");
	safe_sem_post(philo->second_fork->sem_fork, "sem_post second fork");
	if (philo->table->nbr_limit_meal > 0
		&& philo->num_of_meals == philo->table->nbr_limit_meal)
		exit(EXIT_PHILO_FULL);
}
