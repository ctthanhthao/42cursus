/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:06:46 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 15:08:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_int(pthread_mutex_t *mtx, int *dest, int value)
{
	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when set int for value.");
		return ;
	}
	*dest = value;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when set int for value.");
		return ;
	}
}

int	get_int(pthread_mutex_t *mtx, int *dest)
{
	int	value;

	if (safe_mutex_handle(mtx, LOCK) == ERROR_MUTEX)
	{
		log_error("Failed to gain lock mutex when get int value.");
		return (ERROR_MUTEX);
	}
	value = *dest;
	if (safe_mutex_handle(mtx, UNLOCK) == ERROR_MUTEX)
	{
		log_error("Failed to unlock mutex when get int value.");
		return (ERROR_MUTEX);
	}
	return (value);
}
