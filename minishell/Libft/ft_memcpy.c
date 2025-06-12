/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:41:41 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
/*
int main (void)
{
    char src[] = "Hello World!";
    char dst[20];

    ft_memcpy(dst, src, 5);
    dst[5] = '\0';

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return (0);
}
*/
