/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:21:24 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:13:54 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	handle_width(unsigned int width, unsigned int len, int zero)
{
	int		count;
	char	pad_char;

	if (zero == 1)
		pad_char = '0';
	else
		pad_char = ' ';
	count = 0;
	while (width > len)
	{
		count += ft_printchar(pad_char);
		width--;
	}
	return (count);
}

static int	handle_precision_with_str(char *s, unsigned int len,
										unsigned int min_len)
{
	int	count;

	count = 0;
	if (len < min_len)
		min_len = len;
	while (min_len-- > 0)
	{
		count += ft_printchar(*s);
		s++;
	}
	return (count);
}

static int	handle_precision_with_nums_lzero(char *s, unsigned int len,
											unsigned int m_len, int l_zero)
{
	int				count;
	unsigned int	i;

	count = 0;
	i = 0;
	if (l_zero == 0)
	{
		while (i++ < len)
			count += ft_printchar(*s);
		count += handle_width(m_len, len, 1);
	}
	else
	{
		count += handle_width(m_len, len, 1);
		while (i++ < len)
			count += ft_printchar(*(s++));
	}
	return (count);
}

static int	handle_precision_with_nums(char *s, unsigned int len,
										unsigned int m_len, int l_zero)
{
	int				count;

	count = 0;
	if (m_len == 0 && len == 1 && s[0] == '0')
		return (count);
	if (len > m_len)
		while (len-- > 0)
			count += ft_printchar(*(s++));
	else
		count += handle_precision_with_nums_lzero(s, len, m_len, l_zero);
	return (count);
}

int	handle_precision(char *s, int precision, int is_string, int leading_zero)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (is_string == 1)
		return (handle_precision_with_str(s, len, precision));
	else
		return (handle_precision_with_nums(s, len, precision, leading_zero));
}
