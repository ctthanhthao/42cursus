/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handleptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:03:57 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 12:38:13 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	*transform_number(char *num_str, long num)
{
	if (num == 0)
	{
		ft_memcpy(num_str, "(nil)", 5);
		num_str[5] = '\0';
	}
	else
	{
		ft_memset(num_str, 0, sizeof(num_str));
		convert_num_to_hex(num_str, num, 0);
		ft_strreverse(num_str);
	}
	return (num_str);
}

int	ft_handleptr(unsigned long num, t_flags *flags)
{
	int		count;
	int		len;
	char	num_str[17];
	char	*zerox;

	zerox = NULL;
	if (num != 0)
		zerox = ft_strdup("0x");
	transform_number(num_str, num);
	len = ft_strlen(num_str);
	count = 0;
	flags->hash = 1;
	if (flags->minus == 1)
		count += handlehex_minus_hash_dot(num_str, flags, zerox);
	else if (flags->zero == 1)
		count += handlehex_zero_hash_dot(num_str, len, flags, zerox);
	else
		count += handlehex_hash_dot(num_str, len, flags, zerox);
	if (zerox != NULL)
		free(zerox);
	return (count);
}
