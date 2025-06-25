/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:14:40 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 09:39:03 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	update_pwd_env(char ***envp)
{
	char	*cwd;
	char	*new_pwd;
	int		i;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		log_errno(NULL);
		return (CMD_FAILURE);
	}
	new_pwd = ft_strjoin("PWD=", cwd);
	if (!new_pwd)
		return (free(cwd), CMD_FAILURE);
	free(cwd);
	i = -1;
	while ((*envp)[++i])
	{
		if (ft_strncmp((*envp)[i], "PWD=", 4) == 0)
		{
			free((*envp)[i]);
			(*envp)[i] = new_pwd;
			return (CMD_SUCCESS);
		}
	}
	return (free(new_pwd), CMD_FAILURE);
}

int	cd_builtin(t_cmd *cmd, char ***envp)
{
	char	*path;

	if (cmd->argv[1] == NULL)
		path = getenv("HOME");
	else if (cmd->argv[2])
	{
		log_errno("too many arguments");
		return (CMD_FAILURE);
	}
	else
		path = cmd->argv[1];
	if (chdir(path) != 0)
	{
		perror("cd");
		return (return_failed_exit_code());
	}
	if (update_pwd_env(envp) == CMD_FAILURE)
		return (log_errno("PWD not found in environment"), CMD_FAILURE);
	return (CMD_SUCCESS);
}
