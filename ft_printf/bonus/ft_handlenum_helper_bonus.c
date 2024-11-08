/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenum_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:06:48 by thchau            #+#    #+#             */
/*   Updated: 2024/11/08 15:56:17 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	check_sign_or_space(int sign, t_flags *flags)
{
	if (sign < 0)
		return ('-');
	else if (flags->plus == 1)
		return ('+');
	else if (flags->space == 1)
		return (' ');
	return ('\0');
}

int	handledi_minus_dot(char *num_str, int sign, t_flags *flags)
{
	int		count;
	char	c_sign;

	count = 0;
	c_sign = check_sign_or_space(sign, flags);
	if (c_sign != '\0')
		count += ft_printchar(c_sign);
	if (flags->dot == 1)
	{
		count += handle_precision(num_str, flags->precision, 0, 1);
		count += handle_width(flags->width, count, 0);
	}
	else
	{
		count += ft_printchars(num_str);
		count += handle_width(flags->width, count, 0);
	}
	return (count);
}

static int	handledi_zero_dot_sign(char *num_str, unsigned int len,
									t_flags *flags, char csign)
{
	int	count;

	count = 0;
	if (csign != '\0')
		count += 1;
	if (len == 1 && num_str[0] == '0')
		len = 0;
	if (flags->precision > (int)len)
		count += handle_width(flags->width, flags->precision + count, 0);
	else
		count += handle_width(flags->width, len + count, 0);
	if (csign != '\0')
		ft_printchar(csign);
	count += handle_precision(num_str, flags->precision, 0, 1);
	return (count);
}

int	handledi_zero_dot(char *num_str, unsigned int len, int sign, t_flags *flags)
{
	int		count;
	char	c_sign;

	count = 0;
	c_sign = check_sign_or_space(sign, flags);
	if (flags->dot == 1)
		count += handledi_zero_dot_sign(num_str, len, flags, c_sign);
	else
	{
		if (c_sign != '\0')
			count += ft_printchar(c_sign);
		count += handle_width(flags->width, len + count, 1);
		if (len != 0 || num_str[0] != '0')
			count += ft_printchars(num_str);
	}
	return (count);
}

int	handledi_dot(char *num_str, unsigned int len, int sign, t_flags *flags)
{
	int		count;
	char	c_sign;

	count = 0;
	c_sign = check_sign_or_space(sign, flags);
	if (flags->dot == 1)
		count += handledi_zero_dot_sign(num_str, len, flags, c_sign);
	else
	{
		if (c_sign != '\0')
			count += 1;
		count += handle_width(flags->width, len + count, 0);
		if (c_sign != '\0')
			ft_printchar(c_sign);
		count += ft_printchars(num_str);
	}
	return (count);
}
