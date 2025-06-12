/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_group_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:12:27 by thchau            #+#    #+#             */
/*   Updated: 2025/06/10 12:44:30 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	execute_group(t_ast *node, int *last_status, char ***envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (log_errno(NULL), CMD_FAILURE);
	if (pid == 0)
	{
		status = apply_redirections(node->redirs, *last_status, *envp);
		if (status != CMD_SUCCESS)
			exit(status);
		exit(execute_ast(node->left, last_status, envp));
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 130)
			g_heredoc_interrupted = 1;
		return (WEXITSTATUS(status));
	}
	return (128 + WTERMSIG(status));
}
