/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:01:45 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 09:43:47 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printhex(unsigned long num, int isUpper)
{
	char	*base_digits;
	char	buffer[16];
	int		count;		
	int		i;

	if (num == 0)
		return (ft_printchar('0'));
	if (isUpper == 0)
		base_digits = "0123456789abcdef";
	else
		base_digits = "0123456789ABCDEF";
	i = 0;
	count = 0;
	while (num > 0 && i < 16)
	{
		buffer[i] = base_digits[num % 16];
		num /= 16;
		i++;
	}
	while (--i >= 0)
		count += ft_printchar(buffer[i]);
	return (count);
}

int	ft_printptr(unsigned long num)
{
	int		count;		

	if (num == 0)
		return (ft_printchars("(nil)"));
	count = 0;
	count += ft_printchars("0x");
	count += ft_printhex(num, 0);
	return (count);
}

int	ft_printdi(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_printchars("-2147483648"));
	else if (n < 0)
	{
		count += ft_printchar('-');
		n = n * (-1);
	}
	if (n < 10)
	{
		count += ft_printchar(n + '0');
		return (count);
	}
	return (count + ft_printdi(n / 10) + ft_printchar(n % 10 + '0'));
}

int	ft_printu(unsigned int n)
{
	if (n < 10)
		return (ft_printchar(n + '0'));
	return (ft_printu(n / 10) + ft_printchar(n % 10 + '0'));
}
