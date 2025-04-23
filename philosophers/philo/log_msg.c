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

#include "philosophers.h"

void	log_error(const char *error)
{
	printf(R "%s\n" RST, error);
}

static void	print_take_fork_msg(t_philo_action action, t_philo *philo,
	long timestamp, long elapsed)
{
	if (action == TAKE_FIRST_FORK)
		printf(G"%ld(%ld) %d has taken fork[%d]\n"RST, timestamp, elapsed,
			philo->id, philo->first_fork->fork_id);
	else
		printf(G"%ld(%ld) %d has taken fork[%d]\n"RST, timestamp, elapsed,
			philo->id, philo->second_fork->fork_id);
}

static bool	log_action_debug(t_philo_action action, t_philo *philo)
{
	long	elapsed;
	long	timestamp;
	int		id;
	int		meal_count;

	if (safe_mutex_handle(&philo->table->write_mtx, LOCK) == ERROR_MUTEX)
		return (false);
	timestamp = get_time(MILLISECOND);
	elapsed = timestamp - philo->table->start_simulation;
	id = get_int(&philo->mtx, &philo->id);
	meal_count = get_int(&philo->mtx, &philo->num_of_meals);
	if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->table))
		print_take_fork_msg(action, philo, timestamp, elapsed);
	else if (action == EATING && !simulation_finished(philo->table))
		printf(B"%ld(%ld) %d is eating -- meal counter: %d\n"RST, timestamp,
			elapsed, id, meal_count);
	else if (action == SLEEPING && !simulation_finished(philo->table))
		printf("%ld(%ld) %d is sleeping\n", timestamp, elapsed, id);
	else if (action == THINKING && !simulation_finished(philo->table))
		printf("%ld(%ld) %d is thinking\n", timestamp, elapsed, id);
	else if (action == DIED && !simulation_finished(philo->table))
		printf(Y"%ld(%ld) %d died\n"RST, timestamp, elapsed, id);
	else
		return (safe_mutex_handle(&philo->table->write_mtx, UNLOCK), false);
	if (safe_mutex_handle(&philo->table->write_mtx, UNLOCK) == ERROR_MUTEX)
		return (false);
	return (true);
}

bool	log_action(t_philo_action action, t_philo *philo)
{
	long	now;
	int		id;

	if (DEBUG_MODE == 1)
		return (log_action_debug(action, philo));
	if (safe_mutex_handle(&philo->table->write_mtx, LOCK) == ERROR_MUTEX)
		return (false);
	now = get_time(MILLISECOND);
	id = get_int(&philo->mtx, &philo->id);
	if (id == ERROR_MUTEX)
		return (safe_mutex_handle(&philo->table->write_mtx, UNLOCK), false);
	if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->table))
		printf(G"%ld %d has taken a fork\n"RST, now, id);
	else if (action == EATING && !simulation_finished(philo->table))
		printf(B"%ld %d is eating\n"RST, now, id);
	else if (action == SLEEPING && !simulation_finished(philo->table))
		printf("%ld %d is sleeping\n", now, id);
	else if (action == THINKING && !simulation_finished(philo->table))
		printf("%ld %d is thinking\n", now, id);
	else if (action == DIED && !simulation_finished(philo->table))
		printf(Y"%ld %d died\n"RST, now, id);
	else
		return (safe_mutex_handle(&philo->table->write_mtx, UNLOCK), false);
	if (safe_mutex_handle(&philo->table->write_mtx, UNLOCK) == ERROR_MUTEX)
		return (false);
	return (true);
}
