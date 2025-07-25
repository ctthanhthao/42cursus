/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:42:49 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 20:45:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	expect_end_input(int fd_write, char *delimiter, int last_status,
	char **envp)
{
	char	*line;
	char	*expand_line;
	char	*heredoc_buffer;

	heredoc_buffer = ft_strdup("");
	while (1)
	{
		line = readline("> ");
		if (g_heredoc_interrupted || !line || !ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		expand_line = expand_variables(line, last_status, envp);
		heredoc_buffer = ft_strjoin_free(heredoc_buffer, expand_line);
		heredoc_buffer = ft_strjoin_free(heredoc_buffer, "\n");
		free(expand_line);
		free(line);
	}
	if (g_heredoc_interrupted == 0)
		write(fd_write, heredoc_buffer, ft_strlen(heredoc_buffer));
	free(heredoc_buffer);
	safe_close_fd(&fd_write);
	if (g_heredoc_interrupted == 1)
		exit(130);
}

static int	do_heredoc(t_redir *redir, int last_status, char **envp,
	int *fds)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (log_errno(NULL), CMD_FAILURE);
	if (pid == 0)
	{
		signal(SIGINT, heredoc_sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		safe_close_fd(&fds[0]);
		expect_end_input(fds[1], redir->filename, last_status, envp);
		exit(CMD_SUCCESS);
	}
	safe_close_fd(&fds[1]);
	waitpid(pid, &status, 0);
	if ((WIFEXITED(status) && WEXITSTATUS(status) == 130)
		|| (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT))
	{
		if (WEXITSTATUS(status) == 130)
			return (safe_close_fd(&fds[0]), write(STDOUT_FILENO, "\n", 1), 130);
		return (safe_close_fd(&fds[0]), CMD_FAILURE);
	}
	return (CMD_SUCCESS);
}

int	process_single_heredoc(t_redir *redir, int last_status, char **envp)
{
	int	fd[2];
	int	status;

	if (pipe(fd) == -1)
	{
		log_errno("Error happened when pipe fd in process_heredoc");
		return (-1);
	}
	status = do_heredoc(redir, last_status, envp, fd);
	if (status != CMD_SUCCESS)
	{
		safe_close_fds(fd);
		if (status == 130)
			g_heredoc_interrupted = 1;
		return (-1);
	}
	return (fd[0]);
}

int	process_heredoc(t_cmd *cmd, int last_status, char **envp)
{
	int		cur_fd;
	t_redir	*cur;

	g_heredoc_interrupted = 0;
	cur = cmd->redirs;
	while (cur)
	{
		if (cur->type == REDIR_HEREDOC)
		{
			cur_fd = process_single_heredoc(cur, last_status, envp);
			if (cur_fd == -1)
				return (safe_close_fd(&cmd->heredoc_fd), CMD_FAILURE);
			if (cmd->heredoc_fd != -1)
				safe_close_fd(&cmd->heredoc_fd);
			cmd->heredoc_fd = cur_fd;
		}
		else if (cur->type == REDIR_IN)
		{
			if (cmd->heredoc_fd != -1)
				safe_close_fd(&cmd->heredoc_fd);
		}
		cur = cur->next;
	}
	signal(SIGINT, sigint_handler);
	return (signal(SIGQUIT, SIG_IGN), CMD_SUCCESS);
}
