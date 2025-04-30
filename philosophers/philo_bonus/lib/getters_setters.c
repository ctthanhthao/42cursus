/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:25:49 by thchau            #+#    #+#             */
/*   Updated: 2025/04/29 18:53:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	set_bool(sem_t *sem, bool *dest, bool value)
{
	safe_sem_wait(sem, "sem_wait set_bool");
	*dest = value;
	safe_sem_post(sem, "sem_post set_bool");
}

bool	get_bool(sem_t *sem, bool *dest)
{
	bool	value;

	safe_sem_wait(sem, "sem_wait get_bool");
	value = *dest;
	safe_sem_post(sem, "sem_post get_bool");
	return (value);
}

void	set_long(sem_t *sem, long *dest, long value)
{
	safe_sem_wait(sem, "sem_wait set_long");
	*dest = value;
	safe_sem_post(sem, "sem_post set_long");
}

long	get_long(sem_t *sem, long *dest)
{
	long	value;

	safe_sem_wait(sem, "sem_wait get_long");
	value = *dest;
	safe_sem_post(sem, "sem_post get_long");
	return (value);
}

bool	simulation_finished(t_table *tb)
{
	return (get_bool(tb->sem_end, &tb->end_simulation));
}
