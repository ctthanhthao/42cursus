/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:26:00 by thchau            #+#    #+#             */
/*   Updated: 2025/06/10 12:47:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	safe_close(int *fds)
{
	if (!fds)
		return ;
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
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
		close(oldfd);
		log_errno("Error duplicating file descriptor");
		return (CMD_FAILURE);
	}
	close(oldfd);
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
	while (i < old_size && argv[i])
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i] = NULL;
	free(argv);
	return (new_argv);
}
