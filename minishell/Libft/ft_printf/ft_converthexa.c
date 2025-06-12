/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:12:46 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/04 11:55:32 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_addhash(t_flags flags, int is_upper)
{
	int	length;

	length = 0;
	if (flags.hash == 1)
	{
		length += ft_printc('0');
		if (is_upper)
			length += ft_printc('X');
		else
			length += ft_printc('x');
	}
	return (length);
}

int	ft_hexa_formatter(int is_upper, t_flags flags, int len)
{
	int	padding;
	int	total_len;

	padding = 0;
	total_len = len;
	if (flags.hash)
		len += 2;
	if (flags.width > total_len)
	{
		padding += flags.width - len;
		{
			if (flags.left == 0)
			{
				while (padding-- > 0)
				{
					if (flags.zero == 1 && flags.precision == -1)
						total_len += ft_printc('0');
					else
						total_len += ft_printc(' ');
				}
			}
		}
	}
	total_len += ft_addhash(flags, is_upper);
	return (total_len);
}

void	ft_printhexa(char *str)
{
	int	i;

	i = (ft_strlen(str) - 1);
	while (i >= 0)
	{
		ft_printc(str[i]);
		i--;
	}
	return ;
}

char	*ft_converter(unsigned long nr, int is_upper)
{
	long	temp;
	char	*hexa_nr;
	int		i;

	hexa_nr = (char *)malloc(100 * sizeof(char));
	if (!hexa_nr)
		return (NULL);
	i = 0;
	while (nr != 0)
	{
		temp = nr % 16;
		if (temp < 10)
			hexa_nr[i++] = temp + 48;
		else
		{
			if (is_upper)
				hexa_nr[i++] = temp + 55;
			else
				hexa_nr[i++] = temp + 87;
		}
		nr /= 16;
	}
	hexa_nr[i] = '\0';
	return (hexa_nr);
}

int	ft_converthexa(unsigned long nr, int is_upper, t_flags flags)
{
	char	*hexa_nr;
	int		length;

	if (nr == 0)
		return (ft_printchar('0', flags));
	hexa_nr = ft_converter(nr, is_upper);
	if (!hexa_nr)
		return (-1);
	length = ft_hexa_formatter(is_upper, flags, ft_strlen(hexa_nr));
	ft_printhexa(hexa_nr);
	length += ft_left_allign(flags, length);
	free (hexa_nr);
	return (length);
}
/*
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_printchar.c"
#include "ft_printstring.c"
#include "ft_flags.c"
#include "ft_flag_determin.c"
int main(void)
{
    t_flags flags;

    flags = ft_flags_init();
    flags.width = 20;
    flags.zero = 0;
    flags.plus = 0;
    flags.left = 0;
    flags.space = 0;
    flags.hash = 0;
    
    int num = 48879;
    int nr1 = printf("%20x", num);   // Output: ff
    write(1, "\n", 1);
    int nr2 = ft_converthexa(num, 0, flags);
    write(1, "\n", 1);
    int nr3 = printf("%20X", num);   // Output: FF
    write(1, "\n", 1);
    int nr4 = ft_converthexa(num, 1, flags);   // Output: FF
    write(1, "\n", 1);
    printf("%i\n",nr1);
    printf("%i\n",nr2);
    printf("%i\n",nr3);
    printf("%i\n",nr4);
    return 0;
}
*/
