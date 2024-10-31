/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlehex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:04:40 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 15:02:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	*update_zerox(char *num_str, int hash, char *zerox, int is_upper)
{
	unsigned int	len;

	len = ft_strlen(num_str);
	if (hash == 1)
	{
		if (is_upper == 1 && (num_str[0] != '0' || len != 1))
			zerox = ft_strdup("0X");
		else if (is_upper == 0 && (num_str[0] != '0' || len != 1))
			zerox = ft_strdup("0x");
	}
	return (zerox);
}

int	ft_handlehex(unsigned long num, t_flags *flags, int is_upper)
{
	char			num_str[17];
	int				count;
	char			*zerox;
	unsigned int	len;

	count = 0;
	zerox = NULL;
	ft_memset(num_str, 0, sizeof(num_str));
	convert_num_to_hex(num_str, num, is_upper);
	ft_strreverse(num_str);
	len = ft_strlen(num_str);
	zerox = update_zerox(num_str, flags->hash, zerox, is_upper);
	if (flags->minus == 1)
		count += handlehex_minus_hash_dot(num_str, flags, zerox);
	else if (flags->zero == 1)
		count += handlehex_zero_hash_dot(num_str, len, flags, zerox);
	else
		count += handlehex_hash_dot(num_str, len, flags, zerox);
	free(zerox);
	return (count);
}
