/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_msg_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:21 by thchau            #+#    #+#             */
/*   Updated: 2025/04/16 20:50:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_message(char *msg)
{
	write (1, msg, ft_length(msg));
}

void	log_error(const char *error)
{
	write(2, error, ft_length(error));
	write (1, "\n", 1);
}

bool	log_action(t_philo_action action, t_philo *philo)
{
	long	elapsed;
	long	timestamp;

	if (safe_mutex_handle(&philo->table->write_mtx, LOCK) == ERROR_MUTEX)
		return (false);
	timestamp = get_time(MILLISECOND);
	elapsed = timestamp - philo->table->start_simulation;
	if ((action == TAKE_FIRST_FORK || action == TAKE_SECOND_FORK)
		&& !simulation_finished(philo->table))
	{
		printf("%ld(%ld) %d has taken a fork\n", timestamp, elapsed, philo->id);
		if (action == TAKE_FIRST_FORK)
			printf("%ld(%ld) %d has taken fork[%d]\n", timestamp, elapsed, philo->id, philo->first_fork->fork_id);
		else
			printf("%ld(%ld) %d has taken fork[%d]\n", timestamp, elapsed, philo->id, philo->second_fork->fork_id);
	}
	else if (action == EATING && !simulation_finished(philo->table))
		printf("%ld(%ld) %d is eating\n", timestamp, elapsed, philo->id);
	else if (action == SLEEPING && !simulation_finished(philo->table))
		printf("%ld(%ld) %d is sleeping\n", timestamp, elapsed, philo->id);
	else if (action == THINKING && !simulation_finished(philo->table))
		printf("%ld(%ld) %d is thinking\n", timestamp, elapsed, philo->id);
	else if (action == DIED && !simulation_finished(philo->table))
		printf("%ld(%ld) %d died\n", timestamp, elapsed, philo->id);
	else
		return (false);
	if (safe_mutex_handle(&philo->table->write_mtx, UNLOCK) == ERROR_MUTEX)
		return (false);
	return (true);
}