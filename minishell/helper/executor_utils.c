/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:23:15 by thchau            #+#    #+#             */
/*   Updated: 2025/06/13 15:53:17 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*build_path_and_test(char **paths, char *cmd, int *status)
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
	log_errno_more(cmd, "command not found");
	*status = 127;
	return (NULL);
}

static bool	is_directory(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0 && S_ISDIR(st.st_mode))
		return (true);
	return (false);
}

static bool	is_executable(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
	{
		log_errno(NULL);
		return (false);
	}
	if ((st.st_mode & S_IXUSR && st.st_uid == getuid())
		|| (st.st_mode & S_IXGRP && st.st_gid == getgid())
		|| (st.st_mode & S_IXOTH))
		return (true);
	return (false);
}

static char	*handle_backslash_in_cmd(char *cmd, int *status)
{
	if (access(cmd, F_OK) != 0)
	{
		log_errno_more(cmd, "No such file or directory");
		*status = 127;
		return (NULL);
	}
	if (is_directory(cmd))
	{
		log_errno_more(cmd, "Is a directory");
		*status = 126;
		return (NULL);
	}
	if (!is_executable(cmd))
	{
		log_errno_more(cmd, "Permission denied");
		*status = 126;
		return (NULL);
	}
	return (ft_strdup(cmd));
}

/**
 * If cmd starts with a slash, treat as path
 * Else we'll build full path which is combined from valid path in env 
 * with given cmd
 */
char	*find_valid_path(char *cmd, char **envp, int *status)
{
	char	**paths;
	char	*path_env;
	char	*full_path;
	int		i;

	path_env = NULL;
	full_path = NULL;
	if (ft_strchr(cmd, '/'))
		return (handle_backslash_in_cmd(cmd, status));
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
	full_path = build_path_and_test(paths, cmd, status);
	return (free_split(paths), full_path);
}
