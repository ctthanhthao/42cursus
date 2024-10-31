/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:18:43 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:23:56 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*itoa(char *str, unsigned int len, long n)
{
	while (n != 0)
	{
		if (n < 0)
			str[--len] = -(n % 10) + '0';
		else
			str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	char			*str;
	long			num;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	num = n;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (itoa(str, len, n));
}
