/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:41:46 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}
//TEST
/*
#include <string.h>
#include <stdlib.h>
int main (void)
{
    char buffer[20];
    char expected[20];

    strcpy(buffer, "Hello World!");
    strcpy(expected, "Hello World!");

    ft_memset(buffer + 6, '*', 5);
    memset(expected + 6, '*', 5);


    printf("ft_memset result: %s\n", buffer);
    printf("expected result: %s\n", expected);

    if(strcmp(buffer, expected) == 0)
    {
        printf("Test passed! :)\n");
    }
    else
    {
        printf("Test failed! :(\n)");
    }

    return (0);
}
*/
