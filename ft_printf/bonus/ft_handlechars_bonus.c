/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlechars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:42:24 by thchau            #+#    #+#             */
/*   Updated: 2024/11/07 08:51:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static char	*makeup_chars_if_dot(char *arg, int has_dot, int precision)
{
	char	*result;

	if (arg == NULL)
	{
		if (has_dot == 1 && precision < 6)
			result = ft_strdup("");
		else
			result = ft_strdup("(null)");
	}
	else
		result = ft_strdup(arg);
	return (result);
}

int	ft_handlechars(char *arg, t_flags *flags)
{
	int		count;
	int		len;
	char	*copy;

	count = 0;
	copy = makeup_chars_if_dot(arg, flags->dot, flags->precision);
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
