/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:44:37 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 14:58:44 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
	{
		++i;
	}
	return (i);
}
/*
#include <stdio.h>

int main() {
	char src[] = "Hello, world!";
	char dst[6];

	size_t len = ft_strlcpy(dst, src, sizeof(dst));

	printf("dst = %s\n", dst);       // Output: "Hello"
	printf("len = %zu\n", len);      // Output: 13 (length of src)
}*/
