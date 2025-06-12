/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:18:30 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 17:05:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static const char	*node_color(t_node_type type)
{
	if (type == NODE_CMD)
		return (COLOR_CMD);
	else if (type == NODE_PIPE)
		return (COLOR_OP);
	else if (type == NODE_AND)
		return (COLOR_OP);
	else if (type == NODE_OR)
		return (COLOR_OP);
	else if (type == NODE_GROUP)
		return (COLOR_GROUP);
	else
		return (COLOR_RESET);
}

static char	*prepare_prefix(const char *prefix, int is_last, char *new_prefix)
{
	char	*full_prefix;

	full_prefix = ft_strjoin_free(new_prefix, (char *)prefix);
	if (is_last)
		full_prefix = ft_strjoin_free(full_prefix, "    ");
	else
		full_prefix = ft_strjoin_free(full_prefix, "|   ");
	return (full_prefix);
}

static void	print_argv(char **argv)
{
	int	i;

	ft_printf(": ");
	i = 0;
	while (*argv[i])
		ft_printf("%s ", *argv[i++]);
}

static void	print_ast_node(t_ast *node, const char *prefix, int is_last)
{
	char	*new_prefix;

	if (!node)
		return ;
	if (is_last)
		ft_printf("%s└── ", prefix);
	else
		ft_printf("%s├── ", prefix);
	ft_printf("%s%s", node_color(node->type), node_type_str(node->type));
	if (node->type == NODE_CMD && node->cmd && node->cmd->argv)
		print_argv(node->cmd->argv);
	ft_printf(COLOR_RESET"\n");
	new_prefix = NULL;
	new_prefix = prepare_prefix(prefix, is_last, new_prefix);
	if (node->left)
		print_ast_node(node->left, new_prefix, !node->right);
	if (node->right)
		print_ast_node(node->right, new_prefix, 1);
	print_redirections(node, new_prefix);
	free(new_prefix);
}

void	print_ast(t_ast *root)
{
	print_ast_node(root, "", 1);
}
