/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:02:21 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 21:17:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	execute_cmd(t_ast *node, int last_status, char ***envp, bool should_fork)
{
	int		status;
	t_cmd	*cmd;

	cmd = node->cmd;
	if ((!cmd->argv || !*cmd->argv) && cmd->redirs)
	{
		status = handle_builtin_with_redirection(cmd, envp, &last_status, NULL);
		if (status == 130)
			g_heredoc_interrupted = 1;
		return (status);
	}
	if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exit_builtin_bonus(node, last_status, envp);
	status = execute_single_command(cmd, envp, &last_status, should_fork);
	if (status == 130)
		g_heredoc_interrupted = 1;
	return (status);
}
