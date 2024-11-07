/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:02:31 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 09:55:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_conversions(const char **str, va_list args, t_flags *flags)
{
	if (**str == '%')
		return (ft_printchar('%'));
	if (**str == 'c')
		return (ft_handlechar(va_arg(args, int), flags));
	if (**str == 's')
		return (ft_handlechars(va_arg(args, char *), flags));
	if (**str == 'p')
		return (ft_handleptr(va_arg(args, unsigned long), flags));
	if (**str == 'd' || **str == 'i')
		return (ft_handlenum(va_arg(args, int), flags));
	if (**str == 'u')
		return (ft_handlenum(va_arg(args, unsigned int), flags));
	if (**str == 'x')
		return (ft_handlehex(va_arg(args, unsigned int), flags, 0));
	if (**str == 'X')
		return (ft_handlehex(va_arg(args, unsigned int), flags, 1));
	return (ft_printchar('%') + ft_printchar(**str));
}

int	ft_process(const char **str, va_list args)
{
	t_flags	*flags;
	int		count;

	count = 0;
	flags = ft_parseflags(str, args);
	if (flags != NULL && str)
	{
		count += handle_conversions(str, args, flags);
		free(flags);
	}
	return (count);
}
