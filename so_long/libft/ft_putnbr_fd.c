/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:01:13 by thchau            #+#    #+#             */
/*   Updated: 2024/09/21 14:23:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = n * (-1);
	}
	if (n < 10)
	{
		c = n + '0';
		write (fd, &c, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write (fd, &c, 1);
}
/*#include <stdio.h>
int main(void)
{
	int num[5] = {0, -34343, 343424, -2147483648, 2147483647};
	for (int i = 0; i < 5; i++)
	{
		ft_putnbr_fd(num[i], 1);
		write (1, "\n", 1);
	}
	return 0;
}*/