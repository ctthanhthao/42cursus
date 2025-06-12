/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:37:32 by thchau            #+#    #+#             */
/*   Updated: 2025/05/28 11:16:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	handle_backslash(char **p, char **tmp, int in_double, int in_single)
{
	char	*s;

	s = *p;
	if (*s == '\\')
	{
		if ((in_double && *(s + 1) == '$') || (!in_double && !in_single))
			*tmp = ft_substr((*p) + 1, 0, 1);
		else
			*tmp = ft_substr((*p), 0, 2);
		(*p) += 2;
		return (true);
	}
	return (false);
}

static bool	handle_quotes(char **p, int *in_double, int *in_single, char **tmp)
{
	char	c;

	c = **p;
	if (c == '\'' && !*in_double)
	{
		*in_single = !*in_single;
		*tmp = ft_substr(*p, 0, 1);
		(*p)++;
		return (true);
	}
	else if (c == '"' && !*in_single)
	{
		*in_double = !*in_double;
		*tmp = ft_substr(*p, 0, 1);
		(*p)++;
		return (true);
	}
	return (false);
}

static void	handle_text(char **p, int in_double, int in_single, char **tmp)
{
	int		start;
	char	*s;

	if (handle_backslash(p, tmp, in_double, in_single))
		return ;
	start = 0;
	s = *p;
	while (s[start] && ((s[start] != '$' && s[start] != '\\') || in_single))
	{
		if (s[start] == '\'' && !in_double)
			break ;
		if (s[start] == '"' && !in_single)
			break ;
		start++;
	}
	*tmp = ft_substr(s, 0, start);
	(*p) += start;
}
/**
 * It's supposed to apply to an argv in cmd,
 * - If argv contains valid env variables, new argv is returned after 
 * those variables are replaced by their value.
 * - Otherwise, original argv is returned. 
 * It supports
 * + Quotes (' should disable expansion)
 * + Recursive expansion ($FOO_$BAR)
 * + Skipping invalid variable names ($5X or $!)
 */

char	*expand_variables(const char *arg, int last_status, char **env)
{
	char	*p ;
	char	*result;
	char	*tmp;
	int		in_single;
	int		in_double;

	p = (char *)arg;
	result = ft_calloc(1, 1);
	in_single = 0;
	in_double = 0;
	while (*p)
	{
		if (handle_quotes(&p, &in_double, &in_single, &tmp))
			;
		else if (*p == '$' && !in_single)
			tmp = expand_one_var(&p, last_status, env);
		else
			handle_text(&p, in_double, in_single, &tmp);
		result = ft_strjoin_free(result, tmp);
		free(tmp);
	}
	return (result);
}
