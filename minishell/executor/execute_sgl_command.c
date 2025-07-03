/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sgl_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:47:05 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 18:35:05 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	execute_external_cmd_without_fork(t_cmd *cmd, int last_status,
	char ***envp, char *success_path)
{
	int	status;

	status = apply_redirections(cmd, last_status, *envp);
	if (status != CMD_SUCCESS)
		return (status);
	if (execve(success_path, cmd->argv, *envp) == -1)
		return (return_failed_exit_code());
	return (CMD_SUCCESS);
}

static int	execute_external_cmd(t_cmd *cmd, int last_status, char ***envp,
	char *success_path)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (log_errno(NULL), CMD_FAILURE);
	if (pid == 0)
	{
		status = apply_redirections(cmd, last_status, *envp);
		if (status != CMD_SUCCESS)
			exit(status);
		if (execve(success_path, cmd->argv, *envp) == -1)
			exit(return_failed_exit_code());
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (128 + WTERMSIG(status));
}

int	execute_single_command(t_cmd *cmd, char ***envp,
	int *last_status, bool should_fork)
{
	char	*path;
	int		status;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (*last_status);
	if (is_builtin(cmd->argv[0]))
		*last_status = handle_builtin_with_redirection(cmd, envp, last_status,
				execute_builtin);
	else
	{
		status = 0;
		path = find_valid_path(cmd->argv[0], *envp, &status);
		if (!path)
			return (status);
		if (should_fork)
			*last_status = execute_external_cmd(cmd, *last_status, envp, path);
		else
			*last_status = execute_external_cmd_without_fork(cmd, *last_status,
					envp, path);
		if (path)
			free(path);
	}
	if (*last_status == 130)
		g_heredoc_interrupted = 1;
	return (*last_status);
}
