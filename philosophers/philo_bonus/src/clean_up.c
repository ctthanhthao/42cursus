/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:01:46 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 22:10:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static void	clean_philo_data(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->philos[i].table = NULL;
		i++;
	}
}

static void	clean_fork_data(t_table *tb)
{
	int		i;
	char	*sem_fork_msg;

	i = 0;
	while (i < tb->philo_nbr)
	{
		sem_fork_msg = ft_strjoin("sem_close ", tb->forks[i].name);
		safe_sem_close(tb->forks[i].sem_fork, sem_fork_msg);
		safe_sem_unlink(tb->forks[i].name);
		free(sem_fork_msg);
		sem_fork_msg = NULL;
		free(tb->forks[i].name);
		tb->forks[i].name = NULL;
		i++;
	}
}

void	clean_up(t_table *tb)
{
	printf("Clean up in the end ====================.\n");
	safe_sem_close(tb->sem_write, "sem_close write action");
	safe_sem_close(tb->sem_end, "sem_close sync start");
	safe_sem_close(tb->sem_sync, "sem_close sync start");
	safe_sem_close(tb->sem_dead, "sem_close philo start");
	safe_sem_close(tb->sem_meal, "sem_close check meal");
	safe_sem_unlink(SEM_PROTECT_MEAL_FNAME);
	safe_sem_unlink(SEM_DEAD_FNAME);
	safe_sem_unlink(SEM_WRITE_FNAME);
	safe_sem_unlink(SEM_END_SIMULATION_FNAME);
	safe_sem_unlink(SEM_SYNC_START_FNAME);
	clean_philo_data(tb);
	clean_fork_data(tb);
	if (tb->philos)
	{
		free(tb->philos);
		tb->philos = NULL;	
	}
	if (tb->forks)
	{
		free(tb->forks);
		tb->forks = NULL;
	}
}
