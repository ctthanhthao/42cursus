/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:02:58 by phofer            #+#    #+#             */
/*   Updated: 2025/05/28 15:35:50 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_numlen(long n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	size_t	len;
	int		neg;

	nb = n;
	neg = (nb < 0);
	if (neg)
		nb = -nb;
	len = ft_numlen(nb) + neg;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		if (neg && len == 0)
			str[len] = '-';
	}
	return (str);
}
/*
#include <stdio.h>

int main ()
{
	int x = 1234567890;
	int y = 0;
	long z = -2147483648;

	printf("x = %s\ny = %s\nz = %s\n", ft_itoa(x), ft_itoa(y), ft_itoa(z));
	return 0;
}*/
