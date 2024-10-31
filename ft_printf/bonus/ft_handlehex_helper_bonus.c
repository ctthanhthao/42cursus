/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlehex_helper_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:52:55 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 18:14:42 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	*convert_num_to_hex(char *num_str, unsigned long num, int isUpper)
{
	char	*base_digits;	
	int		i;

	if (num == 0)
	{
		num_str[0] = 0 + '0';
		return (num_str);
	}
	if (isUpper == 0)
		base_digits = "0123456789abcdef";
	else
		base_digits = "0123456789ABCDEF";
	i = 0;
	while (num > 0 && i < 16)
	{
		num_str[i] = base_digits[num % 16];
		num /= 16;
		i++;
	}
	num_str[i] = '\0';
	return (num_str);
}

int	handlehex_minus_hash_dot(char *num_str, t_flags *flags, char *zerox)
{
	int	count;

	count = 0;
	if (flags->hash == 1 && zerox != NULL)
		count += ft_printchars(zerox);
	if (flags->dot == 1)
		count += handle_precision(num_str, flags->precision, 0, 1);
	else
		count += ft_printchars(num_str);
	count += handle_width(flags->width, count, 0);
	return (count);
}

static int	handle_width_with_str_len(char *num_str, t_flags *flags,
				unsigned int len, int count)
{
	if (flags->width > count)
	{
		if (len == 1 && num_str[0] == '0')
			len = 0;
		if (flags->precision > (int)len)
			count += handle_width(flags->width - count, flags->precision, 0);
		else
			count += handle_width(flags->width - count, len, 0);
	}
	return (count);
}

int	handlehex_zero_hash_dot(char *num_str, unsigned int len,
							t_flags *flags, char *zerox)
{
	int	count;

	count = 0;
	if (flags->dot == 1)
	{
		if (flags->hash == 1 && zerox != NULL)
			count += 2;
		count = handle_width_with_str_len(num_str, flags, len, count);
		if (flags->hash == 1 && zerox != NULL)
			ft_printchars(zerox);
		count += handle_precision(num_str, flags->precision, 0, 1);
	}
	else
	{
		if (flags->hash == 1 && zerox != NULL)
			count += ft_printchars(zerox);
		if (flags->width > count)
			count += handle_width(flags->width - count, len, 1);
		count += ft_printchars(num_str);
	}
	return (count);
}

int	handlehex_hash_dot(char *num_str, unsigned int len,
						t_flags *flags, char *zerox)
{
	int	count;

	count = 0;
	if (flags->hash == 1 && zerox != NULL)
		count += 2;
	if (flags->dot == 1)
	{
		count = handle_width_with_str_len(num_str, flags, len, count);
		if (flags->hash == 1 && zerox != NULL)
			ft_printchars(zerox);
		count += handle_precision(num_str, flags->precision, 0, 1);
	}
	else
	{
		if (flags->width > count)
			count += handle_width(flags->width - count, len, 0);
		if (flags->hash == 1 && zerox != NULL)
			ft_printchars(zerox);
		count += ft_printchars(num_str);
	}
	return (count);
}
