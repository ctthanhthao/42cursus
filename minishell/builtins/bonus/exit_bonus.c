/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:25:39 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 21:13:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_bonus.h"

void	exit_builtin_bonus(t_ast *node, int status, char ***envp)
{
	t_cmd	*cmd;

	cmd = node->cmd;
	if (!cmd)
		exit(CMD_FAILURE);
	if (!cmd->argv[1])
		;
	else if (cmd->argv[2])
	{
		log_errno("too many arguments");
		status = CMD_FAILURE;
	}
	else
	{
		status = ft_atoi(cmd->argv[1]);
		if (status == 0 && ft_strcmp(cmd->argv[1], "0") != 0)
		{
			log_errno("numeric argument required");
			status = 2;
		}
	}
	free_ast(node);
	free_split(*envp);
	*envp = NULL;
	exit(status);
}
