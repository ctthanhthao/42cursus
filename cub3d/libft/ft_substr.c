/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:12:29 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 18:27:20 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void	sub(char const *s, unsigned int start, size_t len, char *new)
{
	size_t	i;

	i = 0;
	while ((s[start]) && (i < len))
	{
		new[i] = s[start];
		++i;
		++start;
	}
	new[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (len > (s_len - start))
		len = (s_len - start);
	new = malloc((len + 1) * (sizeof(char)));
	if (!new)
		return (NULL);
	sub(s, start, len, new);
	return (new);
}
/*
#include <stdio.h>

int main(void)
{
    char *result;

    // Case 1: Normal usage
    result = ft_substr("Hello, world!", 7, 5);
    printf("Case 1: %s\n", result);
    free(result);

    // Case 2: len longer than remaining string
    result = ft_substr("Hello", 2, 10);
    printf("Case 2: %s\n", result);
    free(result);

    // Case 3: start beyond string length
    result = ft_substr("Short", 10, 3);
    printf("Case 3: %s\n", result);
    free(result);

    // Case 4: empty string
    result = ft_substr("", 0, 5);
    printf("Case 4: %s\n", result);
    free(result);

    // Case 5: len is 0
    result = ft_substr("Hello", 2, 0);
    printf("Case 5: %s\n", result);
    free(result);

    // Case 6: start = 0
    result = ft_substr("Sample", 0, 3);
    printf("Case 6: %s\n", result);
    free(result);

    return 0;
}*/
