/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:38:21 by phofer            #+#    #+#             */
/*   Updated: 2025/06/04 17:23:49 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	print_p_rec(unsigned long addr, int *count)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (addr >= 16)
		print_p_rec(addr / 16, count);
	ft_putchar(digits[addr % 16]);
	(*count)++;
}

void	print_p(int *count, void *ptr)
{
	unsigned long	addr;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	(*count) += 2;
	print_p_rec(addr, count);
}

void	print_num(int *count, int n)
{
	ft_putnbr(count, n);
}

void	print_str(int *count, const char *str)
{
	int	j;

	j = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[j])
	{
		write(1, &str[j], 1);
		(*count)++;
		++j;
	}
}

void	print_c(int *count, int str)
{
	write(1, &str, 1);
	(*count)++;
}
