/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_ast_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:37:50 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 08:48:09 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

/*
* Parse_pipeline handles |
* Higher precedence than && and ||
*/

static t_ast	*parse_pipeline(t_parser *p)
{
	t_ast	*left;
	t_ast	*right;

	left = parse_group_or_command(p);
	if (!left)
		return (NULL);
	while (p->tokeni < p->token_count
		&& ft_strcmp(p->tokens[p->tokeni], "|") == 0)
	{
		p->tokeni++;
		right = parse_group_or_command(p);
		if (!right)
			return (free_ast(left), NULL);
		left = new_ast_node(NODE_PIPE, left, right, NULL);
	}
	return (left);
}
/**
 * Parse_expression handles && and ||
 * Lowest precedence, left-associative
 */

t_ast	*parse_expression(t_parser *p)
{
	t_ast		*left;
	t_ast		*right;
	t_node_type	type;

	left = parse_pipeline(p);
	if (!left)
		return (NULL);
	while (p->tokeni < p->token_count
		&& (ft_strcmp(p->tokens[p->tokeni], "&&") == 0
			|| ft_strcmp(p->tokens[p->tokeni], "||") == 0))
	{
		if (ft_strcmp(p->tokens[p->tokeni], "&&") == 0)
			type = NODE_AND;
		else
			type = NODE_OR;
		p->tokeni++;
		right = parse_pipeline(p);
		if (!right)
			return (free_ast(left), NULL);
		left = new_ast_node(type, left, right, NULL);
	}
	return (left);
}
