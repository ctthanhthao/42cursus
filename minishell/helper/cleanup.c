/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:07:20 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 16:28:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*next;
	t_redir	*tmp_re;

	while (cmd)
	{
		next = cmd->next;
		free_split(cmd->argv);
		while (cmd->redirs)
		{
			tmp_re = cmd->redirs;
			cmd->redirs = cmd->redirs->next;
			if (tmp_re->filename)
				free(tmp_re->filename);
			free(tmp_re);
		}
		free(cmd);
		cmd = next;
	}
}
