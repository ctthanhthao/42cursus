/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:11:32 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/10 12:15:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell_bonus.h"

volatile sig_atomic_t	g_heredoc_interrupted = 0;

static char	*read_input(void)
{
	char				*input;
	static const char	*shell_prompt;

	shell_prompt = BLUE "minishell_bonus$ " RESET;
	input = readline(shell_prompt);
	if (!input)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		return (NULL);
	}
	if (*input)
		add_history(input);
	return (input);
}

static int	minishell_loop(char ***shell_envp, int *last_status)
{
	char	*input;
	t_ast	*root;

	while (1)
	{
		if (g_heredoc_interrupted == 1)
		{
			g_heredoc_interrupted = 0;
			ft_printf("\n");
			continue ;
		}
		input = read_input();
		if (!input)
			break ;
		root = parse_input_bonus(input, *last_status, *shell_envp);
		free(input);
		if (!root)
			continue ;
		*last_status = execute_ast(root, last_status, shell_envp);
		free_ast(root);
		if (*last_status == CMD_EXIT)
			break ;
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
