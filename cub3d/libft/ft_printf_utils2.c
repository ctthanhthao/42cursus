/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:38:11 by phofer            #+#    #+#             */
/*   Updated: 2025/06/04 17:20:59 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int *count, int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		(*count)++;
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(count, (nb / 10));
	ft_putchar((nb % 10) + 48);
	(*count)++;
}

void	print_x(int *count, unsigned int n, char c)
{
	char	*digits;

	if (n == 0)
	{
		ft_putchar('0');
		(*count)++;
		return ;
	}
	if (c == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (n >= 16)
		print_x(count, n / 16, c);
	ft_putchar(digits[n % 16]);
	(*count)++;
}

void	print_u(int *count, unsigned int n)
{
	if (n >= 10)
		print_u(count, n / 10);
	ft_putchar((n % 10) + '0');
	(*count)++;
}
