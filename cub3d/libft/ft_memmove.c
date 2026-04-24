/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:05:09 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 11:36:52 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			++i;
		}
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>


int main(void)
{
    char buffer1[20] = "1234567890";
    char buffer2[20] = "1234567890";

    printf("Before:\n");
    printf("Original buffer1: %s\n", buffer1);
    printf("Original buffer2: %s\n", buffer2);

    // Overlapping copy: dest starts after src
    ft_memmove(buffer1 + 2, buffer1, 6);     
    memmove(buffer2 + 2, buffer2, 6);        // Standard version for comparison

    printf("\nAfter memmove with overlap:\n");
    printf("ft_memmove  result: %s\n", buffer1);
    printf("std memmove result: %s\n", buffer2);

    // Non-overlapping copy test
    char src[] = "HELLO";
    char dest1[10] = "xxxxxxx";
    char dest2[10] = "xxxxxxx";

    ft_memmove(dest1, src, 5);
    memmove(dest2, src, 5);

    printf("\nAfter memmove with no overlap:\n");
    printf("ft_memmove  result: %.*s\n", 7, dest1);
    printf("std memmove result: %.*s\n", 7, dest2);

    return 0;
}*/
