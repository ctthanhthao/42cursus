/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_group_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:24:38 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 11:09:06 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static t_cmd	*parse_command(t_parser *p)
{
	t_cmd	*cmd;
	int		capacity;
	int		argc;

	capacity = 10;
	cmd = new_cmd(capacity);
	argc = 0;
	while (p->tokens[p->tokeni] && !is_logical_op(p->tokens[p->tokeni])
		&& ft_strcmp(p->tokens[p->tokeni], ")") != 0)
	{
		if (ft_is_redirection(p->tokens[p->tokeni]))
		{
			if (parse_redirections_bonus(&cmd->redirs, p) == CMD_FAILURE)
				return (free(cmd), NULL);
			continue ;
		}
		if (handle_expansion_bonus(&cmd->argv, &argc, &capacity, p)
			== CMD_FAILURE)
			return (free(cmd), NULL);
		p->tokeni++;
	}
	return (cmd->argv[argc] = NULL, cmd);
}

static char	*create_err_msg(char *token)
{
	char	*er_msg;

	er_msg = ft_strdup("syntax error near unexpected token '");
	er_msg = ft_strjoin_free(er_msg, token);
	er_msg = ft_strjoin_free(er_msg, "'");
	return (er_msg);
}

static int	validate_group_redirs_and_syntax(t_parser *p, t_redir **redirs)
{
	char	*er_msg;

	p->is_group_node = true;
	if (parse_redirections_bonus(redirs, p) == CMD_FAILURE)
		return (CMD_FAILURE);
	p->is_group_node = false;
	if (p->tokeni < p->token_count && p->tokens[p->tokeni]
		&& !is_logical_op_bonus(p->tokens[p->tokeni]))
	{
		er_msg = create_err_msg(p->tokens[p->tokeni]);
		log_errno(er_msg);
		free(er_msg);
		return (CMD_FAILURE);
	}
	return (CMD_SUCCESS);
}

static t_ast	*parse_group(t_parser *p)
{
	t_redir	*redirs;
	t_ast	*node;
	t_ast	*group;
	char	*er_msg;

	node = NULL;
	redirs = NULL;
	p->tokeni++;
	if (is_logical_op(p->tokens[p->tokeni]))
	{
		er_msg = create_err_msg(p->tokens[p->tokeni]);
		return (log_errno(er_msg), free(er_msg), NULL);
	}
	group = parse_expression(p);
	if (!group)
		return (NULL);
	if (p->tokeni < p->token_count && ft_strcmp(p->tokens[p->tokeni], ")") == 0)
		p->tokeni++;
	else
		return (log_errno("Syntax error: expected ')'"), NULL);
	if (validate_group_redirs_and_syntax(p, &redirs) == CMD_FAILURE)
		return (free_redirs(redirs), free_ast(group), NULL);
	node = new_ast_node(NODE_GROUP, group, NULL, NULL);
	return (node->redirs = redirs, node);
}

t_ast	*parse_group_or_command(t_parser *p)
{
	t_ast	*group;
	t_cmd	*cmd;
	bool	prev_in_group;

	if (p->tokeni < p->token_count && ft_strcmp(p->tokens[p->tokeni], "(") == 0)
	{
		prev_in_group = p->in_group;
		if (prev_in_group)
		{
			log_errno("Syntax error: nested groups not supported");
			return (NULL);
		}
		p->in_group = true;
		group = parse_group(p);
		p->in_group = prev_in_group;
		return (group);
	}
	else
	{
		cmd = parse_command(p);
		if (!cmd)
			return (NULL);
		return (new_ast_node(NODE_CMD, NULL, NULL, cmd));
	}
}
