/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:02:21 by thchau            #+#    #+#             */
/*   Updated: 2025/06/10 12:43:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	execute_cmd(t_cmd *cmd, int *last_status, char ***envp)
{
	int	status;

	if ((!cmd->argv || !*cmd->argv) && cmd->redirs)
	{
		status = handle_builtin_with_redirection(cmd, envp, last_status, NULL);
		if (status == 130)
			g_heredoc_interrupted = 1;
		return (status);
	}
	status = execute_single_command(cmd, envp, last_status, true);
	if (status == 130)
		g_heredoc_interrupted = 1;
	return (status);
}
