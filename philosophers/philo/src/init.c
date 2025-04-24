/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:22:32 by thchau            #+#    #+#             */
/*   Updated: 2025/04/23 20:49:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static void	philos_init(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->philos[i].is_full = false;
		tb->philos[i].num_of_meals = 0;
		tb->philos[i].last_meal_time = -1;
		tb->philos[i].id = i + 1;
		tb->philos[i].has_started = false;
		tb->philos[i].table = tb;
		if (safe_mutex_handle(&tb->philos[i].mtx, INIT) == ERROR_MUTEX)
		{
			log_error("Error happens during initializing philo mtx.");
			return ;
		}
		assign_forks(&tb->philos[i], tb->forks, i);
		i++;
	}
}

static t_error_code	fork_mutexes_init(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->forks[i].fork_id = i;
		if (safe_mutex_handle(&tb->forks[i].fork, INIT) == ERROR_MUTEX)
		{
			log_error("Error happens during initializing forks.");
			return (ERROR_INIT);
		}
		i++;
	}
	return (SUCCESS);
}

t_error_code	data_init(t_table *tb)
{
	tb->end_simulation = 0;
	tb->all_threads_ready = false;
	tb->philos = safe_malloc(sizeof(t_philo) * tb->philo_nbr);
	if (!tb->philos)
		return (ERROR_INIT);
	tb->forks = safe_malloc(sizeof(t_fork) * tb->philo_nbr);
	if (!tb->forks)
		return (ERROR_INIT);
	if (fork_mutexes_init(tb) == ERROR_INIT)
		return (ERROR_INIT);
	if (safe_mutex_handle(&tb->access_mtx, INIT) == ERROR_MUTEX)
	{
		log_error("Error happens when create access_mtx");
		return (ERROR_INIT);
	}
	if (safe_mutex_handle(&tb->write_mtx, INIT) == ERROR_MUTEX)
	{
		log_error("Error happens when create write_mtx");
		return (ERROR_INIT);
	}
	philos_init(tb);
	return (SUCCESS);
}
