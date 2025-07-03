/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:32:50 by thchau            #+#    #+#             */
/*   Updated: 2025/07/02 13:06:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		if (fd < 0)
			return (log_errno_more(files, NULL), free(files), CMD_FAILURE);
		return (free(files), safe_dup2(fd, STDOUT_FILENO, NULL));
	}
	if (type == REDIR_OUT_APPEND)
	{
		fd = open(files, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			return (log_errno_more(files, NULL), free(files), CMD_FAILURE);
		return (free(files), safe_dup2(fd, STDOUT_FILENO, NULL));
	}
	return (CMD_FAILURE);
}

static int	process_read(t_cmd *cmd, t_redir *re, int last_status, char **env)
{
	int		fd;
	char	*files;

	if (re->type == REDIR_IN)
	{
		files = apply_expansion_if_need(re->filename, last_status, env);
		if (!files)
			return (CMD_FAILURE);
		fd = open(files, O_RDONLY);
		if (fd < 0)
			return (log_errno_more(files, NULL), free(files), CMD_FAILURE);
		return (free(files), safe_dup2(fd, STDIN_FILENO, NULL));
	}
	if (cmd->heredoc_fd >= 0)
	{
		if (dup2(cmd->heredoc_fd, STDIN_FILENO) == -1)
		{
			safe_close_fd(&cmd->heredoc_fd);
			return (cmd->heredoc_fd = -1, log_errno(NULL), CMD_FAILURE);
		}
		safe_close_fd(&cmd->heredoc_fd);
	}
	return (CMD_SUCCESS);
}

int	apply_redirections(t_cmd *cmd, int last_status, char **env)
{
	t_redir	*cur;
	int		status;

	status = CMD_SUCCESS;
	if (cmd && !cmd->redirs)
		return (status);
	cur = cmd->redirs;
	while (cur)
	{
		if (cur->filename == NULL)
			return (CMD_FAILURE);
		if (cur->type == REDIR_OUT || cur->type == REDIR_OUT_APPEND)
			status = process_write(cur, cur->type, last_status, env);
		else if (cur->type == REDIR_IN || cur->type == REDIR_HEREDOC)
		{
			status = process_read(cmd, cur, last_status, env);
			while (cur->next && cur->next->type == REDIR_HEREDOC)
				cur = cur->next;
		}
		if (status != CMD_SUCCESS)
			break ;
		cur = cur->next;
	}
	safe_close_fd(&cmd->heredoc_fd);
	return (status);
}
