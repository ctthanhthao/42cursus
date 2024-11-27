/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:54:29 by thchau            #+#    #+#             */
/*   Updated: 2024/11/23 22:30:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ps_atoi(const char *ptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (result * sign);
}

void	swap(int *a, int *b)
{
	int	tmp;
	
	if (!a || !b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}