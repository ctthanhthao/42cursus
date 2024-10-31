/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenum_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:56:59 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:06:47 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handlenum(long num, t_flags *flags)
{
	int				count;
	int				sign;
	unsigned int	len;
	char			*num_str;

	count = 0;
	sign = 0;
	num_str = ft_itoa(num);
	len = ft_strlen(num_str);
	if (num < 0)
		sign = -1;
	if (flags->minus == 1)
		count += handledi_minus_dot(num_str, sign, flags);
	else if (flags->zero == 1)
		count += handledi_zero_dot(num_str, len, sign, flags);
	else
		count += handledi_dot(num_str, len, sign, flags);
	free(num_str);
	return (count);
}
