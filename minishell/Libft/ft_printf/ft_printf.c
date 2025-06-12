/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:39:47 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/29 15:49:42 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_flags(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (ft_ft_isdigit(str[i]))
			*flags = ft_flags_digit(str[i], *flags);
		if (ft_istype(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}

static void	exec_conv(char spec_char, va_list args, int *len, t_flags flags)
{
	if (spec_char == '%')
		*len += ft_printperc(flags);
	else if (spec_char == 'c')
		*len += ft_printchar(va_arg(args, int), flags);
	else if (spec_char == 's')
		*len += ft_printstring(va_arg(args, char *), flags);
	else if (spec_char == 'p')
		*len += ft_printpointer(va_arg(args, void *), flags);
	else if (spec_char == 'd' || spec_char == 'i')
		*len += ft_printdigits(va_arg(args, int), flags);
	else if (spec_char == 'u')
		*len += ft_printunsigned(va_arg(args, unsigned int), flags);
	else if (spec_char == 'x')
		*len += ft_converthexa(va_arg(args, unsigned int), 0, flags);
	else if (spec_char == 'X')
		*len += ft_converthexa(va_arg(args, unsigned int), 1, flags);
}

int	ft_printf(const char *_format, ...)
{
	int		i;
	int		len;
	t_flags	flags;
	va_list	args;

	if (!_format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, _format);
	while (_format[i])
	{
		if (_format[i] == '%')
		{
			flags = ft_flags_init();
			i = ft_parse_flags(_format, i, args, &flags);
			exec_conv(_format[i], args, &len, flags);
		}
		else
			len += write(1, &_format[i], 1);
		i++;
	}
	va_end (args);
	return (len);
}
/*
#include <stdio.h>
#include "ft_printchar.c"
#include "ft_printstring.c"
#include "ft_printdigits.c"
#include "ft_printperc.c"
#include "ft_printpointer.c"
#include "ft_printunsigned.c"
#include "ft_converthexa.c"
#include "ft_strlen.c"
#include <limits.h>
#include "ft_flags.c"
#include "ft_flag_determin.c"
int main (void)
{
    int nr1;
    int nr2;
    char *p = "'sup?";
    
    nr1 = printf("%-2p", 1);
    write(1, "\n", 1);
    nr2 = ft_printf("%-2p", 1);
    write(1, "x", 1);
    write(1, "\n", 1);
    printf("Lenght of a null: %i\n", nr1);
    printf("Lenght of a null: %i\n", nr2);

    return (0);    
}
*/
