/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_group_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:24:38 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 12:46:56 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static t_cmd	*new_cmd(int capacity)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = malloc(sizeof(char *) * capacity);
	if (!cmd->argv)
		return (free(cmd), NULL);
	cmd->redirs = NULL;
	return (cmd);
}

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
			parse_redirections_bonus(&cmd->redirs, p);
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

	er_msg = ft_strdup("Syntax error near token '");
	er_msg = ft_strjoin_free(er_msg, token);
	er_msg = ft_strjoin_free(er_msg, "'");
	return (er_msg);
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
	group = parse_expression(p);
	if (p->tokeni < p->token_count && ft_strcmp(p->tokens[p->tokeni], ")")
		== 0)
		p->tokeni++;
	else
		return (free_ast(group), log_errno("Syntax error: expected ')'"), NULL);
	parse_redirections_bonus(&redirs, p);
	if (p->tokeni < p->token_count && p->tokens[p->tokeni]
		&& !is_logical_op(p->tokens[p->tokeni]))
	{
		er_msg = create_err_msg(p->tokens[p->tokeni]);
		free_ast(group);
		return (free_redirs(redirs), log_errno(er_msg), free(er_msg), NULL);
	}
	node = new_ast_node(NODE_GROUP, group, NULL, NULL);
	return (node->redirs = redirs, node);
}

t_ast	*parse_group_or_command(t_parser *p)
{
	t_ast	*group;
	t_cmd	*cmd;

	if (p->tokeni < p->token_count && ft_strcmp(p->tokens[p->tokeni], "(") == 0)
	{
		group = parse_group(p);
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
