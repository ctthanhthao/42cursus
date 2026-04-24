/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:35:57 by phofer            #+#    #+#             */
/*   Updated: 2025/04/16 13:55:34 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>

size_t ft_strlcat(char *dest, char *src, size_t dstsize);

int main(void)
{
	char buffer[15] = "Hello, ";
	char *to_add = "World!";

	size_t result = ft_strlcat(buffer, to_add, sizeof(buffer));

	printf("Result: %s\n", buffer);         // Expected: "Hello, World!"
	printf("Length tried: %u\n", result);   // Expected: 13

	return 0;
}*/
