/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:14:40 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 18:51:09 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	update_old_pwd_env(char ***envp, char *old_pwd)
{
	char	*old_pwd_entry;
	int		i;

	old_pwd_entry = ft_strjoin("OLDPWD=", old_pwd);
	if (!old_pwd_entry)
		return ;
	i = -1;
	while ((*envp)[++i])
	{
		if (ft_strncmp((*envp)[i], "OLDPWD=", 7) == 0)
		{
			free((*envp)[i]);
			(*envp)[i] = old_pwd_entry;
			break ;
		}
	}
}

static int	update_pwd_env(char ***envp)
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
	char	*old_pwd;

	if (cmd->argv[1] == NULL)
		path = getenv("HOME");
	else if (cmd->argv[2])
	{
		log_errno("too many arguments");
		return (CMD_FAILURE);
	}
	else
		path = cmd->argv[1];
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) != 0)
	{
		perror("cd");
		free(old_pwd);
		return (return_failed_exit_code());
	}
	update_old_pwd_env(envp, old_pwd);
	free(old_pwd);
	if (update_pwd_env(envp) == CMD_FAILURE)
		return (log_errno("PWD not found in environment"), CMD_FAILURE);
	return (CMD_SUCCESS);
}
