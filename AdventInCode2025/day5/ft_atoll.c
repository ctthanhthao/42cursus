/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:34:01 by thchau            #+#    #+#             */
/*   Updated: 2025/12/02 13:46:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoll(const char *ptr)
{
	unsigned long long	result;

	result = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (result);
}