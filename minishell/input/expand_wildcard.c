/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:11:36 by thchau            #+#    #+#             */
/*   Updated: 2025/05/30 12:46:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	match_pattern(const char *pattern, const char *str)
{
	if (!*pattern)
		return (!*str);
	if (*pattern == '*')
	{
		while (*pattern == '*')
			pattern++;
		if (!*pattern)
			return (1);
		while (*str)
		{
			if (match_pattern(pattern, str))
				return (1);
			str++;
		}
		return (0);
	}
	else if (*pattern == *str)
		return (match_pattern(pattern + 1, str + 1));
	return (0);
}

char	**expand_wildcard(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;
	int				i;

	matches = malloc(sizeof(char *) * 1024);
	if (!matches)
		return (NULL);
	i = 0;
	dir = opendir(".");
	if (!dir)
		return (free(matches), NULL);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.' && pattern[0] != '.')
			continue ;
		if (match_pattern(pattern, entry->d_name))
			matches[i++] = ft_strdup(entry->d_name);
	}
	if (i == 0)
		matches[i++] = ft_strdup(pattern);
	return (matches[i] = NULL, closedir(dir), matches);
}
