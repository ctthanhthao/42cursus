/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:25:49 by thchau            #+#    #+#             */
/*   Updated: 2025/05/01 10:12:02 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

long	get_long(sem_t *sem, long *dest)
{
	long	value;

	safe_sem_wait(sem, "sem_wait get_long");
	value = *dest;
	safe_sem_post(sem, "sem_post get_long");
	return (value);
}

int	get_int(sem_t *sem, int *dest)
{
	int	value;

	safe_sem_wait(sem, "sem_wait get_int");
	value = *dest;
	safe_sem_post(sem, "sem_post get_int");
	return (value);
}
