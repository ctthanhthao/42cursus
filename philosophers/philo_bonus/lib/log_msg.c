/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:21 by thchau            #+#    #+#             */
/*   Updated: 2025/04/23 11:48:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	log_error(const char *error)
{
	printf(R "%s\n" RST, error);
}

static void	print_take_fork_msg(t_philo_action action, t_philo *philo,
	long timestamp, long elapsed)
{
	if (action == TAKE_FIRST_FORK)
		printf(G"%ld(%ld) %d has taken fork[%d]\n"RST, timestamp, elapsed,
			philo->id, philo->first_fork->id);
	else
		printf(G"%ld(%ld) %d has taken fork[%d]\n"RST, timestamp, elapsed,
			philo->id, philo->second_fork->id);
}

static void	log_action_debug(t_philo_action action, t_philo *philo)
{
	long	elapsed;
	long	now;
	int		id;
	int		meal_counter;

	now = get_time(MILLISECOND);
	elapsed = now - philo->table->start_simulation;
	id = philo->id;
	meal_counter = get_int(philo->table->sem_meal, &philo->num_of_meals);
	if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK))
		print_take_fork_msg(action, philo, now, elapsed);
	else if (action == EATING)
		printf(B"%ld(%ld) %d is eating -- meal counter: %d\n"RST,
			now, elapsed, id, meal_counter);
	else if (action == SLEEPING)
		printf("%ld(%ld) %d is sleeping\n", now, elapsed, id);
	else if (action == THINKING)
		printf("%ld(%ld) %d is thinking\n", now, elapsed, id);
	else if (action == DIED)
		printf(Y"%ld(%ld) %d died\n"RST, now, elapsed, id);
}

void	log_action(t_philo_action action, t_philo *philo)
{
	long	now;
	int		id;

	safe_sem_wait(philo->table->sem_write, "sem_wait write action");
	if (DEBUG_MODE == 1)
		log_action_debug(action, philo);
	else
	{
		now = get_time(MILLISECOND);
		id = philo->id;
		if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK))
			printf(G"%ld %d has taken a fork\n"RST, now, id);
		else if (action == EATING)
			printf(B"%ld %d is eating\n"RST, now, id);
		else if (action == SLEEPING)
			printf("%ld %d is sleeping\n", now, id);
		else if (action == THINKING)
			printf("%ld %d is thinking\n", now, id);
		else if (action == DIED)
			printf(Y"%ld %d died\n"RST, now, id);
	}
	safe_sem_post(philo->table->sem_write, "sem_post write action");
}
