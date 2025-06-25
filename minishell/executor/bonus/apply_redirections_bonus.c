/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:53:25 by thchau            #+#    #+#             */
/*   Updated: 2025/06/23 09:52:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static char	*apply_expansion_if_need(char *file_name, int last_status,
	char **env)
{
	char	**expanded;
	int		i;
	char	*files;

	files = NULL;
	expanded = handle_expansion_if_any(file_name, last_status, env);
	if (!expanded)
		return (NULL);
	i = 0;
	while (expanded[i])
	{
		files = ft_strjoin_free(files, expanded[i]);
		if (expanded[i + 1])
			files = ft_strjoin_free(files, " ");
		i++;
	}
	free_split(expanded);
	if (i == 0)
		return (log_errno_more(file_name, "No such file or directory"), NULL);
	else if (i > 1)
		return (log_errno_more(file_name, "ambiguous redirect"), NULL);
	return (files);
}

static int	process_write(t_redir *re, int type, int last_status, char **env)
{
	int		fd;
	char	*files;

	files = apply_expansion_if_need(re->filename, last_status, env);
	if (!files)
		return (CMD_FAILURE);
	if (type == REDIR_OUT)
	{
		fd = open(files, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(files);
		return (safe_dup2(fd, STDOUT_FILENO, NULL));
	}
	if (type == REDIR_OUT_APPEND)
	{
		fd = open(files, O_WRONLY | O_CREAT | O_APPEND, 0644);
		free(files);
		return (safe_dup2(fd, STDOUT_FILENO, NULL));
	}
	return (CMD_FAILURE);
}

static int	process_read(t_ast *node, int type, int last_status, char **env)
{
	int		fd;
	char	*files;

	if (type == REDIR_IN)
	{
		files = apply_expansion_if_need(node->redirs->filename,
				last_status, env);
		if (!files)
			return (CMD_FAILURE);
		fd = open(files, O_RDONLY);
		return (free(files), safe_dup2(fd, STDIN_FILENO, NULL));
	}
	return (CMD_FAILURE);
}

int	apply_group_redirections(t_ast *node, int last_status, char **env)
{
	t_redir	*cur;
	int		status;

	status = CMD_SUCCESS;
	if (node->redirs == NULL)
		return (status);
	cur = node->redirs;
	while (cur)
	{
		if (cur->filename == NULL)
			return (CMD_FAILURE);
		if (cur->type == REDIR_OUT || cur->type == REDIR_OUT_APPEND)
			status = process_write(cur, cur->type, last_status, env);
		else if (cur->type == REDIR_IN)
		{
			status = process_read(node, cur->type, last_status, env);
		}
		if (status == !CMD_SUCCESS)
			break ;
		cur = cur->next;
	}
	return (status);
}
