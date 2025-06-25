/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:23:05 by thchau            #+#    #+#             */
/*   Updated: 2025/06/16 19:48:09 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	contains_unquoted_star(char *str)
{
	bool	in_single;
	bool	in_double;

	in_single = false;
	in_double = false;
	while (*str)
	{
		if (*str == '\'' && !in_double)
			in_single = !in_single;
		else if (*str == '\"' && !in_single)
			in_double = !in_double;
		else if (*str == '*' && !in_single && !in_double)
			return (true);
		str++;
	}
	return (false);
}

char	**handle_expansion_if_any(char *token, int last_status, char **envp)
{
	char	*expanded;
	char	**wildcards;
	char	**res;

	if (!token)
		return (NULL);
	expanded = expand_variables(token, last_status, envp);
	if (!expanded)
		return (NULL);
	if (contains_unquoted_star(expanded))
	{
		wildcards = expand_wildcard(expanded);
		free(expanded);
		return (wildcards);
	}
	res = ft_calloc(2, sizeof(char *));
	res[0] = remove_quotes_if_need(expanded);
	free(expanded);
	return (res[1] = NULL, res);
}
