/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:17 by thchau            #+#    #+#             */
/*   Updated: 2025/04/20 17:19:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

sem_t	*safe_sem_open(const char *name, int oflag, mode_t mode,
	unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, oflag, mode, value);
	if (sem == SEM_FAILED)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return (sem);
}

void	safe_sem_wait(sem_t *sem, const char *name)
{
	if (sem_wait(sem) == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
}

void	safe_sem_post(sem_t *sem, const char *name)
{
	if (sem_post(sem) == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
}

void	safe_sem_close(sem_t *sem, const char *name)
{
	if (sem_close(sem) == -1)
		perror(name);
}

void	safe_sem_unlink(const char *name)
{
	if (sem_unlink(name) == -1)
	{
		if (errno != ENOENT)
			perror("sem_unlink");
	}
}