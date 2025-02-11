/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:47:19 by thchau            #+#    #+#             */
/*   Updated: 2024/09/20 11:41:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set) == 1)
		end--;
	copy = (char *)malloc((end - start + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (start < end)
	{
		copy[i] = s1[start];
		i++;
		start++;
	}
	copy[i] = 0;
	return (copy);
}
/*#include <stdio.h>
int main()
{
	char *s = "----+a----";
	char *set = "-+";
	char *r = ft_strtrim(s, set);
	printf("Result is %s\n", r);
	return (1);
}*/