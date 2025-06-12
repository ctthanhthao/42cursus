/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redirections_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:58:36 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 17:08:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

void	print_redirections(t_ast *node, const char *prefix)
{
	const char	*type_str;
	t_redir		*redir_list;

	redir_list = NULL;
	if (node->type == NODE_CMD && node->cmd && node->cmd->redirs)
		redir_list = node->cmd->redirs;
	if (node->type == NODE_GROUP && node->redirs)
		redir_list = node->redirs;
	while (redir_list)
	{
		if (redir_list->type == REDIR_IN)
			type_str = "<";
		else if (redir_list->type == REDIR_OUT)
			type_str = ">";
		else if (redir_list->type == REDIR_OUT_APPEND)
			type_str = ">>";
		else if (redir_list->type == REDIR_HEREDOC)
			type_str = "<<";
		else
			type_str = "?";
		ft_printf("%s    └── " COLOR_REDIR "redir: %s %s" COLOR_RESET "\n",
			prefix, type_str, redir_list->filename);
		redir_list = redir_list->next;
	}
}
