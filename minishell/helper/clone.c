/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:10:16 by thchau            #+#    #+#             */
/*   Updated: 2025/06/17 08:25:20 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_created_elements(char **ar, int to_pos)
{
	int	k;

	k = 0;
	while (k < to_pos)
	{
		free(ar[k]);
		ar[k] = NULL;
		k++;
	}
}

char	**clone_arr(char **ar)
{
	int		len;
	int		i;
	char	**copy;

	if (!ar || !*ar)
		return (NULL);
	len = 0;
	i = 0;
	while (ar[len])
		len++;
	copy = malloc(sizeof(char *) * (len + 1));
	if (!copy)
		return (NULL);
	while (ar[i])
	{
		copy[i] = ft_strdup(ar[i]);
		if (!copy[i])
		{
			free_created_elements(copy, i);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy[i] = NULL, copy);
}

static char	*get_file_name(char *name)
{
	char	*file_name;

	if (name)
		file_name = ft_strdup(name);
	else
		file_name = NULL;
	return (file_name);
}

static t_redir	*clone_redirs(t_redir *redirs)
{
	t_redir	*new_redirs;

	if (!redirs)
		return (NULL);
	new_redirs = malloc(sizeof(t_redir));
	new_redirs->type = redirs->type;
	new_redirs->filename = get_file_name(redirs->filename);
	new_redirs->next = clone_redirs(redirs->next);
	return (new_redirs);
}

t_cmd	*clone_cmd(t_cmd *cmd)
{
	t_cmd	*new_cmd;

	if (!cmd)
		return (NULL);
	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->argv = clone_arr(cmd->argv);
	if (cmd->argv && *cmd->argv && (!new_cmd->argv || !*new_cmd->argv))
		return (free(new_cmd), NULL);
	new_cmd->redirs = clone_redirs(cmd->redirs);
	if (cmd->redirs && !new_cmd->redirs)
	{
		free_split(new_cmd->argv);
		return (free(new_cmd), NULL);
	}
	new_cmd->heredoc_fd = cmd->heredoc_fd;
	new_cmd->next = clone_cmd(cmd->next);
	if (cmd->next && !new_cmd->next)
		return (free_cmd(new_cmd), NULL);
	new_cmd->next_type = cmd->next_type;
	return (new_cmd);
}
