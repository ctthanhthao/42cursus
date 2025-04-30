/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_philo_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 07:40:45 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 22:28:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static void	dinner_simulation(t_philo *philo)
{
	safe_sem_wait(philo->table->sem_sync, "sem_wait sync start");
	if (trigger_monitor_death(philo) == ERROR_DINNER_START)
	{
		log_error("Failed to trigger monitor dead philos.");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		philo_eats(philo);
		philo_sleeps(philo);
		philo_thinks(philo);
	}
}

static void	sync_all_processes(t_table *tb)
{
	int	i;

	i = -1;
	while (++i < tb->philo_nbr)
		safe_sem_post(tb->sem_sync, "sem_post sync start");
}

static void	kill_exist_processes(t_table *tb, int to_pos)
{
	int	i;

	i = -1;
	while (++i < to_pos)
		kill(tb->philos[i].pid, SIGINT);
}

t_error_code	trigger_philos_processes(t_table *tb)
{
	int		i;

	i = 0;
	sync_all_processes(tb);
	while (i < tb->philo_nbr)
	{
		tb->philos[i].pid = fork();
		if (tb->philos[i].pid < 0)
			return (kill_exist_processes(tb, i), FAILURE);
		else if (tb->philos[i].pid == 0)
		{
			dinner_simulation(&tb->philos[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
		usleep(100);
	}
	return (SUCCESS);
}