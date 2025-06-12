/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:20:25 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/03 17:33:09 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_uint_len(unsigned int nr)
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

int	ft_udigit_format(t_flags flags, int len)
{
	int	padding;

	padding = 0;
	if (flags.plus)
		len += ft_printc('+');
	if (flags.width > len)
	{
		padding += flags.width - len;
		{
			if (flags.left == 0)
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

int	ft_printu(unsigned int nr)
{
	if (nr > 9)
		ft_printu(nr / 10);
	ft_printc((nr % 10) + '0');
	return (0);
}

int	ft_printunsigned(unsigned int nr, t_flags flags)
{
	int	len;

	len = ft_uint_len(nr);
	len = ft_udigit_format(flags, len);
	ft_printu(nr);
	len += ft_left_allign(flags, len);
	return (len);
}
/*
#include "stdio.h"
#include "ft_printchar.c"
#include "limits.h"
#include "ft_flags.c"
#include "ft_flag_determin.c"
int main (void)
{
    t_flags flags;

    flags = ft_flags_init();
    flags.width = 5;
    flags.zero = 0;
    flags.plus = 0;
    flags.left = 0;
    flags.space = 0;
    int nr = 42;
    int len1 = printf("%.5u", nr);
    write(1, "\n", 1);
    int len2 = ft_printdigits(nr, flags);
    write(1, "n", 1);
    write(1, "\n", 1);
    printf("%i\n", len1);
    printf("%i\n", len2);

    return (0);
}
*/
