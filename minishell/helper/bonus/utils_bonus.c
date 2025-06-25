/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:06 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/23 09:33:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

t_cmd	*new_cmd(int capacity)
{
	t_cmd	*cmd;
	int		i;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = malloc(sizeof(char *) * capacity);
	if (!cmd->argv)
		return (free(cmd), NULL);
	i = 0;
	while (i < capacity)
	{
		cmd->argv[i] = NULL;
		i++;
	}
	cmd->redirs = NULL;
	cmd->heredoc_fd = -1;
	return (cmd);
}

t_ast	*new_ast_node(t_node_type type, t_ast *left, t_ast *right, t_cmd *cmd)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = left;
	node->right = right;
	node->cmd = cmd;
	node->redirs = NULL;
	return (node);
}

t_redir	*new_redirections(t_token type, char *filename)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->type = type;
	new->filename = ft_strdup(filename);
	new->next = NULL;
	return (new);
}

char	*node_type_str(t_node_type type)
{
	if (type == NODE_CMD)
		return ("CMD");
	else if (type == NODE_PIPE)
		return ("PIPE - |");
	else if (type == NODE_AND)
		return ("AND - &&");
	else if (type == NODE_OR)
		return ("OR - ||");
	else if (type == NODE_GROUP)
		return ("GROUP - ()");
	else
		return ("UNKNOWN");
}

void	read_from_fd(int fd)
{
	char	buffer[1024];
	ssize_t	bytes;

	if (fd == -1)
		return ;
	while (true)
	{
		bytes = read(fd, buffer, sizeof(buffer));
		if (bytes > 0)
			write(STDOUT_FILENO, buffer, bytes);
		else
			break ;
	}
}
