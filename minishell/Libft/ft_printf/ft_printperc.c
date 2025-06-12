/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printperc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:34:00 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/04 09:22:00 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printperc(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 0)
		count += ft_pad_width(flags.width, 1, flags.zero);
	count += ft_printchar('%', flags);
	if (flags.left == 1)
		count += ft_pad_width(flags.width, 1, 0);
	return (count);
}
/*
# include "ft_printchar.c"
# include "stdio.h"
int main (void)
{
    printf("%%\n");
    ft_printperc();
    write(1, "\n", 1);
    return (0);
}
*/
