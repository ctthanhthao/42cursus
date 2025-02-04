/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:42:46 by thchau            #+#    #+#             */
/*   Updated: 2025/01/21 10:05:39 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	handler(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putstr_fd("Received:\t", 1);
		ft_putnbr_fd(received, 1);
		ft_putendl_fd("", 1);
		ft_putendl_fd("", 1);
		exit(0);
	}
}

void	send_msg(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("<Usage>: ./client <server pid> <message>", 1);
		return (1);
	}
	ft_putstr_fd("Sent:\t", 1);
	ft_putstr_fd(argv[2], 1);
	ft_putendl_fd("", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
