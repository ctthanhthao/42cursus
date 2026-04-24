/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgahrama <zgahrama@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:21:09 by phofer            #+#    #+#             */
/*   Updated: 2026/02/25 13:59:03 by zgahrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		j;
	int		i;
	char	*ptr;

	i = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL || !src)
	{
		return (NULL);
	}
	j = 0;
	while (j <= i)
	{
		ptr[j] = src[j];
		++j;
	}
	return (ptr);
}
/*
int main(void)
{
    char *original = "Hello, 42!";
    char *copy;

    copy = ft_strdup(original);

    if (copy == NULL)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }

    printf("Original: %s\n", original);
    printf("Copy:     %s\n", copy);

    // Free the allocated memory
    free(copy);

    return 0;
}*/
