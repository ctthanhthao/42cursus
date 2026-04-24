/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:57:03 by phofer            #+#    #+#             */
/*   Updated: 2025/05/23 18:48:45 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>  // For comparison
int main(void)
{
    char buffer1[20];
    char buffer2[20];

    // Fill both buffers with '.'
    memset(buffer1, '.', sizeof(buffer1));
    memset(buffer2, '.', sizeof(buffer2));

    // Null-terminate so we can print them
    buffer1[19] = '\0';
    buffer2[19] = '\0';

    // Use standard memset and your ft_memset
    memset(buffer1, 'X', 10);
    ft_memset(buffer2, 'X', 10);

    printf("Standard memset : %s\n", buffer1);
    printf("ft_memset  : %s\n", buffer2);

    return 0;
}*/
