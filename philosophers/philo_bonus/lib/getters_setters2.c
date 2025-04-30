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

#include "../include/philosophers_bonus.h"

void	set_int(sem_t *sem, int *dest, int value)
{
	safe_sem_wait(sem, "sem_wait set_int");
	*dest = value;
	safe_sem_post(sem, "sem_post set_int");
}

int	get_int(sem_t *sem, int *dest)
{
	int	value;

	safe_sem_wait(sem, "sem_wait get_int");
	value = *dest;
	safe_sem_post(sem, "sem_post get_int");
	return (value);
}
