/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:01:46 by thchau            #+#    #+#             */
/*   Updated: 2025/04/27 17:56:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		free(tb->forks[i].name);
		tb->forks[i].name = NULL;
		i++;
	}
}

void	clean_up(t_table *tb)
{
	safe_sem_close(tb->sem_write, "sem_close write action");
	safe_sem_close(tb->sem_start, "sem_close sync start");
	safe_sem_close(tb->sem_last_meal, "sem_close last meal");
	safe_sem_unlink(SEM_WRITE_FNAME);
	safe_sem_unlink(SEM_SYNC_START_FNAME);
	safe_sem_unlink(SEM_LAST_MEAL_FNAME);
	clean_philo_data(tb);
	clean_fork_data(tb);
	if (tb->philos)
		free(tb->philos);
	if (tb->forks)
		free(tb->forks);
}
