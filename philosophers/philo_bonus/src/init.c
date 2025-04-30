/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:22:32 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 22:09:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	if (philo_nbr == 1)
		philo->first_fork = &forks[position];
	else
	{
		philo->first_fork = &forks[(position + 1) % philo_nbr];
		philo->second_fork = &forks[position];
		if (position % 2 == 1)
		{
			philo->first_fork = &forks[position];
			philo->second_fork = &forks[(position + 1) % philo_nbr];
		}
	}
}

static int	init_philo(t_table *tb)
{
	int		i;
	char	*id;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->philos[i].num_of_meals = 0;
		tb->philos[i].last_meal_time = -1;
		tb->philos[i].id = i + 1;
		tb->philos[i].table = tb;
		id = ft_itoa(i);
		free(id);
		id = NULL;
		assign_forks(&tb->philos[i], tb->forks, i);
		i++;
	}
	return (SUCCESS);
}

static void	clean_local_data(t_fork *forks, int to_pos, char **id, char **name)
{
	int	i;

	i = 0;
	while (i < to_pos)
	{
		sem_close(forks[i].sem_fork);
		sem_unlink(forks[i].name);
		i++;
	}
	free(*id);
	free(*name);
}

static int	init_fork(t_table *tb)
{
	int		i;
	char	*id;
	char	*f_name;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->forks[i].id = i;
		id = ft_itoa(i);
		f_name = ft_strjoin(FORK_PREFIX, id);
		safe_sem_unlink(f_name);
		tb->forks[i].name = ft_strdup(f_name);
		tb->forks[i].sem_fork = sem_open(f_name, O_CREAT, 0664, 1);
		if (tb->forks[i].sem_fork == SEM_FAILED)
		{
			perror("sem_open");
			return (clean_local_data(tb->forks, i, &id, &f_name), FAILURE);
		}
		free(id);
		free(f_name);
		id = NULL;
		f_name = NULL;
		i++;
	}
	return (SUCCESS);
}

t_error_code	init_data(t_table *tb)
{
	tb->philos = safe_malloc(sizeof(t_philo) * tb->philo_nbr);
	if (!tb->philos)
		return (ERROR_INIT);
	tb->forks = safe_malloc(sizeof(t_fork) * tb->philo_nbr);
	if (!tb->forks)
		return (ERROR_INIT);
	tb->start_simulation = 0;
	tb->end_simulation = false;
	tb->sem_write = safe_sem_open(SEM_WRITE_FNAME, O_CREAT, 0644, 1);
	tb->sem_end = safe_sem_open(SEM_END_SIMULATION_FNAME, O_CREAT, 0644, 1);
	tb->sem_sync = safe_sem_open(SEM_SYNC_START_FNAME, O_CREAT, 0644, 0);
	tb->sem_dead = safe_sem_open(SEM_DEAD_FNAME, O_CREAT, 0644, 1);
	tb->sem_meal = safe_sem_open(SEM_PROTECT_MEAL_FNAME, O_CREAT, 0644, 1);
	if (init_fork(tb) == FAILURE || init_philo(tb) == FAILURE)
		return (ERROR_INIT);
	return (SUCCESS);
}
