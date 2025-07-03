/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:06:17 by thchau            #+#    #+#             */
/*   Updated: 2025/07/03 20:49:42 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// 130 Convention: 128 + SIGINT
void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	g_heredoc_interrupted = 1;
	write(STDOUT_FILENO, "\n", 1);
	close(STDIN_FILENO);
}

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

/** 
 * This function is called when the user presses 
 * Ctrl-C (SIGINT) and SIGQUIT (Ctrl-'\').
 */
void	setup_signals(void)
{
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
