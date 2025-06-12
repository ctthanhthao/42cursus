/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:08:08 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 12:22:15 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

void	free_redirs(t_redir *re)
{
	t_redir	*tmp_re;

	if (!re)
		return ;
	while (re)
	{
		tmp_re = re;
		re = re->next;
		if (tmp_re->filename)
			free(tmp_re->filename);
		free(tmp_re);
	}
}

void	free_ast(t_ast *node)
{
	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	if (node->cmd)
		free_cmd(node->cmd);
	free_redirs(node->redirs);
	free(node);
}
