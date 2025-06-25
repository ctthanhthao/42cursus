/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_heredoc_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 06:26:31 by thchau            #+#    #+#             */
/*   Updated: 2025/06/22 22:51:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	preprocess_heredocs_bonus(t_ast *node, int last_status, char **envp)
{
	int		status;

	if (!node)
		return (CMD_SUCCESS);
	status = CMD_SUCCESS;
	if (node->type == NODE_CMD && node->cmd && node->cmd->redirs)
		return (process_heredoc(node->cmd, last_status, envp));
	status = preprocess_heredocs_bonus(node->left, last_status, envp);
	if (status != CMD_SUCCESS)
		return (status);
	status = preprocess_heredocs_bonus(node->right, last_status, envp);
	if (status != CMD_SUCCESS)
		return (status);
	return (status);
}
