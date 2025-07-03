/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:17:35 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 21:02:49 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static void	execute_child_pipeline(t_pid_pipe_fd *pipe_data, t_ast *cur,
	t_ast *left)
{
	signal(SIGPIPE, SIG_DFL);
	if (cur->right)
		dup2(pipe_data->pipe_fd[1], STDOUT_FILENO);
	if (pipe_data->prev_fd != -1)
		dup2(pipe_data->prev_fd, STDIN_FILENO);
	if (cur->right || left->type == NODE_GROUP)
	{
		safe_close_fd(&pipe_data->pipe_fd[0]);
		safe_close_fd(&pipe_data->pipe_fd[1]);
	}
	if (pipe_data->prev_fd != -1)
		safe_close_fd(&pipe_data->prev_fd);
	if (left->type == NODE_PIPE)
		exit(execute_pipe(left, pipe_data->last_status, pipe_data->envp));
	else if (left->type == NODE_CMD)
		exit(execute_cmd(left, pipe_data->last_status, pipe_data->envp,
				false));
	else if (left->type == NODE_GROUP)
		exit(execute_group(left, pipe_data->last_status, pipe_data->envp));
	else
	{
		log_errno("invalid node in pipeline");
		exit(CMD_FAILURE);
	}
}

static void	init_pipe_data(t_pid_pipe_fd *pipe_data, int last_status,
	char ***envp)
{
	pipe_data->prev_fd = -1;
	pipe_data->child_count = 0;
	pipe_data->last_status = last_status;
	pipe_data->envp = envp;
}

static void	update_parent_pipe_fds(t_pid_pipe_fd *pipe_data, pid_t pid,
	t_ast *cur)
{
	if (cur->right)
		safe_close_fd(&pipe_data->pipe_fd[1]);
	if (pipe_data->prev_fd != -1)
		safe_close_fd(&pipe_data->prev_fd);
	if (cur->right)
		pipe_data->prev_fd = pipe_data->pipe_fd[0];
	else
		safe_close_fd(&pipe_data->prev_fd);
	pipe_data->pids[pipe_data->child_count++] = pid;
}

static int	pipeline_fork_and_execute(t_pid_pipe_fd *pipe_data, t_ast *cur,
	t_ast *left)
{
	pid_t	pid;

	if ((cur->right || left->type == NODE_GROUP)
		&& pipe(pipe_data->pipe_fd) == -1)
		return (log_errno(NULL), CMD_FAILURE);
	if (pipe_data->child_count >= 99)
	{
		log_errno("The number of processes has exceeded 100.");
		return (2);
	}
	pid = fork();
	if (pid == -1)
		return (log_errno(NULL), CMD_FAILURE);
	if (pid == 0)
		execute_child_pipeline(pipe_data, cur, left);
	else
		update_parent_pipe_fds(pipe_data, pid, cur);
	return (CMD_SUCCESS);
}

int	execute_pipe(t_ast *node, int last_status, char ***envp)
{
	t_ast			*cur;
	t_ast			*left;
	int				status;
	t_pid_pipe_fd	pipe_data;

	init_pipe_data(&pipe_data, last_status, envp);
	cur = node;
	while (cur)
	{
		if (cur->type == NODE_PIPE)
			left = cur->left;
		else
			left = cur;
		status = pipeline_fork_and_execute(&pipe_data, cur, left);
		if (status == CMD_FAILURE)
			return (CMD_FAILURE);
		else if (status == 2)
			break ;
		cur = cur->right;
	}
	safe_close_fd(&pipe_data.prev_fd);
	safe_close_fds(pipe_data.pipe_fd);
	collect_pipeline_status(&pipe_data, &pipe_data.last_status);
	return (pipe_data.last_status);
}
