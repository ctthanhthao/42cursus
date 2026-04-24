/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:15:20 by phofer            #+#    #+#             */
/*   Updated: 2025/05/26 17:38:35 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static size_t	ft_trimlen(char const *s1, char const *set, size_t *start)
{
	size_t	end;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	if (end == 0)
		return (0);
	--end;
	while (s1[*start] && ft_in_set(s1[*start], set))
		++(*start);
	if (s1[*start] == '\0')
		return (0);
	while (end > *start && ft_in_set(s1[end], set))
		--end;
	return (end - *start + 1);
}

static char	*ft_allocpy(const char *s1, size_t start, size_t len)
{
	char	*new;
	size_t	i;

	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s1[start + i];
		++i;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = (ft_trimlen(s1, set, &start));
	if (len == 0)
		return (ft_allocpy("", 0, 0));
	return (ft_allocpy(s1, start, len));
}
