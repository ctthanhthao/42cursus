/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sgl_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:47:05 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 12:51:55 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*build_path_and_test(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		full_path = ft_strjoin_path(paths[i], cmd);
		if (full_path == NULL)
			continue ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		if (full_path)
			free(full_path);
	}
	return (NULL);
}

/**
 * If cmd starts with a slash, treat as path
 * Else we'll build full path which is combined from valid path in env 
 * with given cmd
 */
static char	*find_valid_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	path_env = NULL;
	full_path = NULL;
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
	}
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	full_path = build_path_and_test(paths, cmd);
	return (free_split(paths), full_path);
}

static int	execute_external_cmd_without_fork(t_cmd *cmd, int last_status,
	char ***envp, char *success_path)
{
	int	status;

	status = apply_redirections(cmd->redirs, last_status, *envp);
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
		status = apply_redirections(cmd->redirs, last_status, *envp);
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
	char	*success_path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (*last_status);
	if (is_builtin(cmd->argv[0]))
		*last_status = handle_builtin_with_redirection(cmd, envp, last_status,
				execute_builtin);
	else
	{
		success_path = find_valid_path(cmd->argv[0], *envp);
		if (!success_path)
			return (log_errno_more(cmd->argv[0], "command not found"), 127);
		if (should_fork)
			*last_status = execute_external_cmd(cmd, *last_status, envp,
					success_path);
		else
			*last_status = execute_external_cmd_without_fork(cmd, *last_status,
					envp, success_path);
		if (success_path)
			free(success_path);
	}
	if (*last_status == 130)
		g_heredoc_interrupted = 1;
	return (*last_status);
}
