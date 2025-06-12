/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:14 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 12:10:28 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	execute_ast(t_ast *node, int *last_status, char ***envp)
{
	int	left_status;

	if (!node)
		return (CMD_SUCCESS);
	if (node->type == NODE_CMD)
		return (execute_cmd(node->cmd, last_status, envp));
	else if (node->type == NODE_PIPE)
		return (execute_pipe(node->left, node->right, last_status, envp));
	else if (node->type == NODE_AND)
	{
		left_status = execute_ast(node->left, last_status, envp);
		if (left_status == CMD_SUCCESS)
			return (execute_ast(node->right, last_status, envp));
		return (left_status);
	}
	else if (node->type == NODE_OR)
	{
		left_status = execute_ast(node->left, last_status, envp);
		if (left_status != CMD_SUCCESS)
			return (execute_ast(node->right, last_status, envp));
		return (left_status);
	}
	else if (node->type == NODE_GROUP)
		return (execute_group(node, last_status, envp));
	return (CMD_SUCCESS);
}
