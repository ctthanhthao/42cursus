/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:29:58 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/04 10:39:22 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_int_len(int nr)
{
	int	i;

	i = 0;
	if (nr == 0)
		return (1);
	while (nr != 0)
	{
		nr /= 10;
		i++;
	}
	return (i);
}

void	ft_writenr(int nr)
{
	if (nr > 9)
		ft_writenr((nr / 10));
	ft_printc((nr % 10 + '0'));
}

int	ft_left_allign(t_flags flags, int len)
{
	int	padding;
	int	length;

	padding = 0;
	length = 0;
	if (flags.width > len)
	{
		padding += flags.width - len;
		{
			if (flags.left == 1)
			{
				while (padding-- > 0)
				{
					if (flags.zero == 1 && flags.precision == -1)
						length += ft_printc('0');
					else
						length += ft_printc(' ');
				}
			}
		}
	}
	return (length);
}

int	ft_digit_format(int nr, t_flags flags, int len)
{
	int	padding;

	padding = 0;
	if (nr >= 0 && flags.plus)
		len += ft_printc('+');
	if (nr >= 0 && flags.space == 1 && !flags.plus)
		len += ft_printc(' ');
	if (flags.width > len)
	{
		padding += flags.width - len;
		{
			if (flags.left == 0 && nr != 0)
			{
				while (padding-- > 0)
				{
					if (flags.zero == 1 && flags.precision == -1)
						len += ft_printc('0');
					else
						len += ft_printc(' ');
				}
			}
		}
	}
	return (len);
}

int	ft_printdigits(int nr, t_flags flags)
{
	int	len;
	int	total_length;

	total_length = 0;
	len = ft_int_len(nr);
	if (nr < 0)
		len += ft_printc('-');
	len = ft_digit_format(nr, flags, len);
	if (nr == 0 && flags.precision != 0)
		return (ft_printchar('0', flags));
	if (nr == -2147483648)
	{
		write(1, "2147483648", 10);
		return (11);
	}
	if (nr < 0)
		nr *= -1;
	ft_writenr(nr);
	len += ft_left_allign(flags, len);
	total_length += len;
	return (total_length);
}
/*
#include <stdio.h>
#include <limits.h>
#include "ft_printchar.c"
#include "ft_flags.c"
#include "ft_flag_determin.c"
int main (void)
{
    t_flags flags;

    flags = ft_flags_init();
    flags.width = 20;
    flags.zero = 0;
    flags.plus = 0;
    flags.left = 1;
    flags.space = 0;
    int nr = -576;
    int len1 = printf("%-20d", nr);
    write(1, "\n", 1);
    int len2 = ft_printdigits(nr, flags);
    write(1, "\n", 1);
    printf("%i\n", len1);
    printf("%i\n", len2);
    
    nr = INT_MAX;
    ft_printdigits(nr, flags);
    write(1, "\n", 1);
    nr = INT_MIN;
    ft_printdigits(nr, flags);
    write(1, "\n", 1);
    nr = 0;
    ft_printdigits(nr, flags);
    write(1, "\n", 1);
    
    return (0);
}
*/
