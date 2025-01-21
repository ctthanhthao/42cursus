/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:06 by thchau            #+#    #+#             */
/*   Updated: 2025/01/21 09:52:28 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	print_pid(void)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
}

static void	send_ack(pid_t client_pid)
{
	kill(client_pid, SIGUSR2);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", 1);
}

static void	sig_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	data = 0;
	static int				count = 0;
	static pid_t			client_pid;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signo == SIGUSR2)
		data |= 1;
	if (++count == 8)
	{
		count = 0;
		if (data == 0)
		{
			send_ack(client_pid);
			client_pid = 0;
			return ;
		}
		write(1, &data, 1);
		data = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		data <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	print_pid();
	s_sigaction.sa_sigaction = sig_handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
