/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:53:16 by thchau            #+#    #+#             */
/*   Updated: 2024/11/06 12:36:33 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup(const char *src)
{
	size_t	s_len;
	size_t	idx;
	char	*ptr;

	s_len = ft_strlen(src);
	ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx < s_len)
	{
		ptr[idx] = src[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_strlen.c"
int main()
{
    char src[] = "Hello, World!";
    
    // Use ft_strdup to duplicate the string
    char *copy = ft_strdup(NULL);
    char *copy1 = strdup(NULL);
    if (copy && copy1) {
        printf("Original: %s\n", src);
        printf("Copy: %s\n", copy);
		printf("Copy1: %s\n", copy1);
        
        // Free the allocated memory after use
        free(copy);
		free(copy1);
    } else {
        printf("Memory allocation failed\n");
    }
    
    return 0;
}*/