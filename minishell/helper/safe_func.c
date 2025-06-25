/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:26:00 by thchau            #+#    #+#             */
/*   Updated: 2025/06/22 22:35:05 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	safe_close_fds(int fds[])
{
	if (!fds)
		return ;
	safe_close_fd(&fds[0]);
	safe_close_fd(&fds[1]);
}

void	safe_close_fd(int *fd)
{
	if (fd && *fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

int	safe_dup2(int oldfd, int newfd, char *error)
{
	if (oldfd == -1)
	{
		log_errno(error);
		return (CMD_FAILURE);
	}
	if (dup2(oldfd, newfd) == -1)
	{
		safe_close_fd(&oldfd);
		log_errno("Error duplicating file descriptor");
		return (CMD_FAILURE);
	}
	if (oldfd != newfd)
		safe_close_fd(&oldfd);
	return (CMD_SUCCESS);
}

char	**safe_realloc(char **argv, int old_size, int new_size)
{
	char	**new_argv;
	int		i;

	new_argv = malloc(sizeof(char *) * new_size);
	if (!new_argv)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i] = NULL;
	free(argv);
	return (new_argv);
}

char	**safe_alloc(int size)
{
	char	**ar;
	int		i;

	ar = malloc(sizeof(char *) * size);
	if (!ar)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ar[i] = NULL;
		i++;
	}
	return (ar);
}
