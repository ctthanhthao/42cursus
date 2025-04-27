/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:01:46 by thchau            #+#    #+#             */
/*   Updated: 2025/04/27 12:44:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	clean_philo_data(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		tb->philos[i].table = NULL;
		if (safe_mutex_handle(&tb->philos[i].mtx, DESTROY) == ERROR_MUTEX)
		{
			log_error("Error happens during destroying mtx.");
			return ;
		}
		i++;
	}
}

void	clean_up(t_table *tb)
{
	int	i;

	i = 0;
	while (i < tb->philo_nbr)
	{
		if (safe_mutex_handle(&tb->forks[i].fork, DESTROY) == ERROR_MUTEX)
		{
			log_error("Error happens during destroying fork.");
			return ;
		}
		i++;
	}
	clean_philo_data(tb);
	if (tb->forks)
		free(tb->forks);
	if (tb->philos)
		free(tb->philos);
	if (safe_mutex_handle(&tb->access_mtx, DESTROY) == ERROR_MUTEX)
		return (log_error("Error happens when destroying access_mtx"));
	if (safe_mutex_handle(&tb->write_mtx, DESTROY) == ERROR_MUTEX)
		return (log_error("Error happens when destroying write_mtx"));
}
