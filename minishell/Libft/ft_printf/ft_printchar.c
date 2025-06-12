/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:41:23 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/04 09:21:46 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pad_width(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_printc('0');
		else
			count += ft_printc(' ');
		total_width--;
	}
	return (count);
}

int	ft_printchar(char c, t_flags flags)
{
	int	count;

	count = 0;
	if ((flags.space == 1 && !flags.plus) || (flags.plus))
		count++;
	if (flags.left == 1)
		count += ft_printc(c);
	count += ft_pad_width(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_printc(c);
	return (count);
}
/*
#include <stdio.h>
#include "ft_flags.c"
#include "ft_flag_determin.c"
int main()
{
    t_flags flags;
    
    flags = ft_flags_init();
    flags.left = 0;
    flags.width = 5;
    flags.zero = 0;
    ft_printchar('b', flags);
    write(1, "\n", 1);
    printf("%5c", 'b');
    return (0);
}
*/
