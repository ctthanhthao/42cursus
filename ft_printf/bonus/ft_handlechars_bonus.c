/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlechars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:42:24 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:06:22 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handlepercent(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_printchar('%');
		if (flags->width > count)
			count += handle_width(flags->width, count, 0);
	}
	else if (flags->zero == 1)
	{
		if (flags->width > 1)
			count += handle_width(flags->width, 1, 1);
		count += ft_printchar('%');
	}
	else
	{
		if (flags->width > 1)
			count += handle_width(flags->width, 1, 0);
		count += ft_printchar('%');
	}
	return (count);
}

int	ft_handlechar(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_printchar(c);
		count += handle_width(flags->width, 1, 0);
	}
	else
	{
		count += handle_width(flags->width, 1, 0);
		count += ft_printchar(c);
	}
	return (count);
}

static int	handle_chars_minus_dot(char *arg, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot == 1)
		count += handle_precision(arg, flags->precision, 1, 0);
	else
		count += ft_printchars(arg);
	return (count);
}

static int	handle_chars_minus_width(int len, t_flags *flags, int zero)
{
	int	count;

	count = 0;
	if (flags->precision >= 0 && flags->precision <= len)
		count += handle_width(flags->width, flags->precision, zero);
	else
		count += handle_width(flags->width, len, zero);
	return (count);
}

int	ft_handlechars(char *arg, t_flags *flags)
{
	int		count;
	int		len;
	char	*copy;

	count = 0;
	if (arg == NULL)
		copy = ft_strdup("(null)");
	else
		copy = ft_strdup(arg);
	len = ft_strlen(copy);
	if (flags->minus == 1)
	{
		count += handle_chars_minus_dot(copy, flags);
		count += handle_chars_minus_width(len, flags, 0);
	}
	else
	{
		count += handle_chars_minus_width(len, flags, flags->zero);
		count += handle_chars_minus_dot(copy, flags);
	}
	free(copy);
	return (count);
}
