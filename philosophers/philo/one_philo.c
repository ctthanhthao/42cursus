/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:41:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/20 17:43:09 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*start_alone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (safe_mutex_handle(&philo->first_fork->fork, LOCK) == ERROR_MUTEX)
		return (NULL);
	log_action(TAKE_FIRST_FORK, philo);
	if (safe_mutex_handle(&philo->first_fork->fork, UNLOCK) == ERROR_MUTEX)
		return (NULL);
	usleep(philo->table->time_to_die);
	log_action(DIED, philo);
	set_bool(&philo->table->access_mtx, &philo->table->end_simulation, true);
	return (NULL);
}

t_error_code	one_philo(t_table *tb)
{
	tb->start_simulation = get_time(MILLISECOND);
	if (safe_thread_handle(&tb->philos[0].thread,
			&start_alone, &tb->philos[0], CREATE) == ERROR_THREAD)
		return (ERROR_DINNER_START);
	if (safe_thread_handle(&tb->philos[0].thread, NULL,
			NULL, JOIN) == ERROR_THREAD)
		return (ERROR_DINNER_START);
	return (SUCCESS);
}
