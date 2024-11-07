/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:15:10 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 11:07:30 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char d[] = "Hello World!!\0";
	char d1[] = "Hello World!!\0";
	char d3[] = "Hello World!!\0";
	const char s[] = "bye bye\0";
	const char s1[] = "bye bye\0";
	ft_memcpy(NULL, NULL, 7);
	memcpy(d1, NULL, 7);
	memcpy(d3 + 2, d3, 3);
	printf("the result d is %s\n", d);
	printf("the result d1 is %s\n", d1);
	printf("the result d3 is %s\n", d3);
	return 1;
}*/
