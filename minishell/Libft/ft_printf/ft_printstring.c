/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:47:23 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/03 15:40:01 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printstring(char *str, t_flags flags)
{
	int	len;
	int	count;

	len = 0;
	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;
	if (flags.left == 1)
		count += (write(1, str, len));
	count += ft_pad_width(flags.width, len, flags.zero);
	if (flags.left == 0)
		count += write(1, str, len);
	return (count);
}
/*
#include "ft_printchar.c"
#include "ft_strlen.c"
#include "ft_flags.c"
#include "ft_flag_determin.c"
#include <stdio.h>
int main (void)
{
    t_flags flags;

    flags = ft_flags_init();
    flags.precision = 3;
    char txt[] = "Hello World!\n";
    ft_printstring(txt, flags);
    write(1, "\n", 1);
    printf("%.3s",txt);
    //ft_printstring("I feel fine!\n", flags);
    //ft_printstring(NULL, flags);
    
    return (0);
}
*/
