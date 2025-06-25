/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_group_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:12:27 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 09:51:03 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	execute_group(t_ast *node, int last_status, char ***envp)
{
	int		status;
	int		stdin_bk;
	int		stdout_bk;
	bool	redirected;

	stdin_bk = -1;
	stdout_bk = -1;
	redirected = false;
	if (node->redirs)
		redirected = save_original_std_inout(&stdin_bk, &stdout_bk);
	status = apply_group_redirections(node, last_status, *envp);
	if (status != CMD_SUCCESS)
	{
		if (redirected)
			restore_original_std_inout(stdin_bk, stdout_bk);
		return (status);
	}
	status = execute_ast(node->left, last_status, envp);
	if (redirected)
		restore_original_std_inout(stdin_bk, stdout_bk);
	return (status);
}
