/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:41:55 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nr;

	nr = n;
	if (nr < 0)
	{
		write (fd, "-", 1);
		nr *= -1;
	}
	if (nr > 9)
	{
		ft_putnbr_fd (nr / 10, fd);
		ft_putchar_fd ((nr % 10) + '0', fd);
	}
	else
		ft_putchar_fd (nr + '0', fd);
}
/*
#include <limits.h>
int main (void)
{
    int nr = 0;
    ft_putnbr_fd(nr, 1);
    write(1, "\n", 1);
    nr = INT_MAX;
    ft_putnbr_fd(nr, 1);
    write(1, "\n", 1);
    nr = INT_MIN;
    ft_putnbr_fd(nr, 1);
    write(1, "\n", 1);
    nr = -525898;
    ft_putnbr_fd(nr, 1);
    write(1, "\n", 1);

    return (0);
}
*/
