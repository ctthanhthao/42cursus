/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:11:32 by amarcz            #+#    #+#             */
/*   Updated: 2025/07/03 18:37:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

volatile sig_atomic_t	g_heredoc_interrupted = 0;

static bool	should_continue(int *last_status)
{
	if (g_heredoc_interrupted == 1)
	{
		g_heredoc_interrupted = 0;
		ft_printf("\n");
		*last_status = 130;
		return (true);
	}
	return (false);
}

static int	execute_command_with_redirections(t_cmd *cmd, int *last_status,
	char ***shell_envp)
{
	if (cmd->redirs)
	{
		*last_status = process_heredoc(cmd, *last_status, *shell_envp);
		if (*last_status != CMD_SUCCESS)
			return (*last_status);
	}
	if (!cmd->argv)
		*last_status = handle_builtin_with_redirection(cmd, shell_envp,
				last_status, NULL);
	else
		*last_status = execute_commands(cmd, shell_envp, last_status);
	return (*last_status);
}

static int	minishell_loop(char ***shell_envp, int *last_status)
{
	char	*input;
	t_cmd	*cmd;

	while (1)
	{
		if (should_continue(last_status))
			continue ;
		input = complete_input();
		if (!input)
			break ;
		cmd = parse_input(input, *last_status, *shell_envp);
		free(input);
		if (!cmd)
		{
			*last_status = 2;
			continue ;
		}
		*last_status = execute_command_with_redirections(cmd, last_status,
				shell_envp);
		free_cmd(cmd);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**shell_envp;
	int		last_status;
	int		ret;

	(void)argc;
	(void)argv;
	last_status = 0;
	shell_envp = clone_arr(envp);
	if (!shell_envp)
		return (1);
	setup_signals();
	ret = minishell_loop(&shell_envp, &last_status);
	free_split(shell_envp);
	return (ret);
}
