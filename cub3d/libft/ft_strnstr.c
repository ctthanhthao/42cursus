/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:33:17 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 13:39:07 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] != '\0'
			&& haystack[i + j] != '\0'
			&& i + j < len
			&& haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Usage: %s <haystack> <needle> <max_len>\n", argv[0]);
		return (1);
	}

	const char *haystack = argv[1];
	const char *needle = argv[2];
	size_t max_len = (size_t)atoi(argv[3]);

	char *result = ft_strnstr(haystack, needle, max_len);

	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return 0;
}*/
