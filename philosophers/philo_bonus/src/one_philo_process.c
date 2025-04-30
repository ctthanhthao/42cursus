/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:41:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 14:52:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static void	start_alone(t_philo *philo)
{
	safe_sem_wait(philo->first_fork->sem_fork,
		"sem_wait fork for only one philo");
	log_action(TAKE_FIRST_FORK, philo);
	custom_usleep(philo->table->time_to_die);
	log_action(DIED, philo);
	safe_sem_post(philo->first_fork->sem_fork,
		"sem_post fork for only one philo");
}

t_error_code	one_philo_process(t_table *tb)
{
	int	status;

	tb->start_simulation = get_time(MILLISECOND);
	tb->philos[0].pid = fork();
	if (tb->philos[0].pid < 0)
		return (ERROR_DINNER_START);
	else if (tb->philos[0].pid == 0)
	{
		start_alone(&tb->philos[0]);
		exit(EXIT_SUCCESS);
	}
	waitpid(-1, &status, 0);
	return (SUCCESS);
}
