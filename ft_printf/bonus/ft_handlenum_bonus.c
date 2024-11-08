/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenum_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:56:59 by thchau            #+#    #+#             */
/*   Updated: 2024/11/08 15:39:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handleu(long num, t_flags *flags)
{
	if (flags->plus == 1 || flags->space == 1)
	{
		flags->plus = 0;
		flags->space = 0;
	}
	return (ft_handledi(num, flags));
}

int	ft_handledi(long num, t_flags *flags)
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
