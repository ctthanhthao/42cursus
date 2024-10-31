/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:53 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:17:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_atoi(const char **ptr)
{
	int	result;

	result = 0;
	while (**ptr >= '0' && **ptr <= '9')
	{
		result = result * 10 + (**ptr - '0');
		(*ptr)++;
	}
	return (result);
}
