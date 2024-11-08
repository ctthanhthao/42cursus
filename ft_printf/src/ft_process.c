/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:32:03 by thchau            #+#    #+#             */
/*   Updated: 2024/11/07 11:36:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_conversions(const char *str, va_list args)
{
	if (*str == '%')
		return (ft_printchar('%'));
	if (*str == 'c')
		return (ft_printchar(va_arg(args, int)));
	if (*str == 's')
		return (ft_printchars(va_arg(args, char *)));
	if (*str == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	if (*str == 'd' || *str == 'i')
		return (ft_printdi(va_arg(args, int)));
	if (*str == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	if (*str == 'x')
		return (ft_printhex(va_arg(args, unsigned int), 0));
	if (*str == 'X')
		return (ft_printhex(va_arg(args, unsigned int), 1));
	return (ft_printchar('%') + ft_printchar(*str));
}

int	ft_process(const char	**str, va_list args)
{
	return (handle_conversions(*str, args));
}
