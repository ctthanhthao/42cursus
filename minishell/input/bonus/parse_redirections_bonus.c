/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirections_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:12:09 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 09:12:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static t_token	get_redir_type(char *token)
{
	t_token	type;

	if (ft_strcmp(token, ">") == 0)
		type = REDIR_OUT;
	else if (ft_strcmp(token, ">>") == 0)
		type = REDIR_OUT_APPEND;
	else if (ft_strcmp(token, "<") == 0)
		type = REDIR_IN;
	else if (ft_strcmp(token, "<<") == 0)
		type = REDIR_HEREDOC;
	else
		type = INVALID;
	return (type);
}

static bool	contains_heredoc(t_parser *p)
{
	if (p->is_group_node && ft_strcmp(p->tokens[p->tokeni], "<<") == 0)
	{
		log_errno("Syntax error: heredoc '<<' not allowed on group");
		return (true);
	}
	return (false);
}

int	parse_redirections_bonus(t_redir **re, t_parser *p)
{
	t_redir	**curr;
	t_token	type;
	t_redir	*new;

	curr = re;
	while (curr && *curr)
		curr = &(*curr)->next;
	while (p->tokens[p->tokeni])
	{
		if (contains_heredoc(p))
			return (CMD_FAILURE);
		type = get_redir_type(p->tokens[p->tokeni]);
		if (type == INVALID)
			break ;
		p->tokeni++;
		if (!p->tokens[p->tokeni])
			return (log_errno("error: expected file name\n"), CMD_FAILURE);
		new = new_redirections(type, p->tokens[p->tokeni++]);
		if (!new)
			return (CMD_FAILURE);
		*curr = new;
		curr = &new->next;
	}
	return (CMD_SUCCESS);
}
