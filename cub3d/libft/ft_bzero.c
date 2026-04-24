/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:40:02 by phofer            #+#    #+#             */
/*   Updated: 2025/05/23 18:53:48 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}
/*
#include <stdio.h>
#include <string.h>  // for standard bzero (on BSD/mac) or memset

int main(void)
{
    char buffer1[10];
    char buffer2[10];

    // Initialize both buffers with 'X'
    memset(buffer1, 'X', sizeof(buffer1));
    memset(buffer2, 'X', sizeof(buffer2));

    // Apply ft_bzero to one, memset to 0 on the other
    ft_bzero(buffer1, 5);        // zero out first 5 bytes
    memset(buffer2, 0, 5);       // standard way to zero memory

    // Print byte-by-byte for comparison
    printf("Index | buffer1 | buffer2\n");
    for (int i = 0; i < 10; ++i)
    {
        printf("  %2d   |   %3d   |   %3d\n", i, 
		(unsigned char)buffer1[i], (unsigned char)buffer2[i]);
    }

    // Optional: verify they match
    if (memcmp(buffer1, buffer2, 10) == 0)
        printf("✅ Buffers match\n");
    else
        printf("❌ Buffers do not match\n");

    return 0;
}
*/
