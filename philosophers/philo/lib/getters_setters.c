/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:25:49 by thchau            #+#    #+#             */
/*   Updated: 2025/04/23 19:59:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value)
{
	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when set bool for value.");
		return ;
	}
	*dest = value;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when set bool for value.");
		return ;
	}
}

bool	get_bool(pthread_mutex_t *mtx, bool *dest)
{
	bool	value;

	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when get bool value.");
		return (false);
	}
	value = *dest;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when get bool value.");
		return (false);
	}
	return (value);
}

void	set_long(pthread_mutex_t *mtx, long *dest, long value)
{
	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when set long for value.");
		return ;
	}
	*dest = value;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when set long for value.");
		return ;
	}
}

long	get_long(pthread_mutex_t *mtx, long *dest)
{
	long	value;

	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when get long value.");
		return (ERROR_MUTEX);
	}
	value = *dest;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when get long value.");
		return (ERROR_MUTEX);
	}
	return (value);
}

bool	simulation_finished(t_table *tb)
{
	return (get_bool(&tb->access_mtx, &tb->end_simulation));
}
