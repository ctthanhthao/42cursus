/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:04:34 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 15:08:10 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	all_philos_started(t_table *tb)
{
	int		i;
	bool	all_started;

	i = 0;
	all_started = true;
	while (i < tb->philo_nbr)
	{
		if (!get_bool(&tb->philos[i].mtx, &tb->philos[i].has_started))
			return (false);
		i++;
	}
	return (all_started);
}
