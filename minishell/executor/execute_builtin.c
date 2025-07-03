/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:42:30 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 18:35:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(const char *cmd)
{
	return (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "pwd"));
}

int	execute_builtin(t_cmd *cmd, char ***envp, int *status)
{
	if (!ft_strcmp(cmd->argv[0], "cd"))
		*status = cd_builtin(cmd, envp);
	else if (!ft_strcmp(cmd->argv[0], "exit"))
		exit_builtin(cmd, *status, envp);
	else if (!ft_strcmp(cmd->argv[0], "export"))
		*status = export_builtin(cmd, envp);
	else if (!ft_strcmp(cmd->argv[0], "unset"))
		*status = unset_builtin(cmd, envp);
	else if (!ft_strcmp(cmd->argv[0], "echo"))
		*status = echo_builtin(cmd, status);
	else if (!ft_strcmp(cmd->argv[0], "env"))
		*status = env_builtin(*envp);
	else if (!ft_strcmp(cmd->argv[0], "pwd"))
		*status = pwd_builtin();
	else
		*status = 1;
	return (*status);
}

int	handle_builtin_with_redirection(t_cmd *cmd, char ***envp, int *status,
	int (*operation)(t_cmd*, char***, int*))
{
	int		stdin_bk;
	int		stdout_bk;
	bool	redirected;
	int		l_status;

	stdin_bk = -1;
	stdout_bk = -1;
	redirected = false;
	l_status = CMD_SUCCESS;
	if (cmd->redirs)
	{
		redirected = save_original_std_inout(&stdin_bk, &stdout_bk);
		l_status = apply_redirections(cmd, *status, *envp);
	}
	if (l_status != CMD_SUCCESS)
	{
		if (redirected)
			restore_original_std_inout(stdin_bk, stdout_bk);
		return (l_status);
	}
	if (operation)
		*status = operation(cmd, envp, status);
	if (redirected)
		restore_original_std_inout(stdin_bk, stdout_bk);
	return (*status);
}
