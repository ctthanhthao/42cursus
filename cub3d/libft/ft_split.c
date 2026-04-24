/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:01:58 by phofer            #+#    #+#             */
/*   Updated: 2025/05/26 19:02:19 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	word_count(const char *s, char delim)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == delim)
			++s;
		if (*s)
			++count;
		while (*s && *s != delim)
			++s;
	}
	return (count);
}

static char	*malloc_word(const char *s, char delim)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != delim)
		++len;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		++i;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **arr, size_t filled)
{
	while (filled > 0)
		free(arr[--filled]);
	free(arr);
}

static int	fill_split(char **arr, const char *s, char c, size_t total)
{
	size_t	i;

	i = 0;
	while (*s && i < total)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = malloc_word(s, c);
			if (!arr[i])
			{
				free_split(arr, i);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	total;
	char	**arr;

	if (!s)
		return (NULL);
	total = word_count(s, c);
	arr = malloc((total + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_split(arr, s, c, total))
		return (NULL);
	return (arr);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	char **result;
	int i = 0;

	if (argc != 3)
	{
		printf("Usage: %s \"string to split\" \"delimiter\"\n", argv[0]);
		return (1);
	}

	if (argv[2][1] != '\0')
	{
		printf("Error: delimiter must be a single character.\n");
		return (1);
	}

	result = ft_split(argv[1], argv[2][0]);
	if (!result)
	{
		printf("Error: ft_split returned NULL\n");
		return (1);
	}

	while (result[i])
	{
		printf("result[%d]: \"%s\"\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);

	return (0);
}*/