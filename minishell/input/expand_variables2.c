/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:44:52 by thchau            #+#    #+#             */
/*   Updated: 2025/05/28 18:56:17 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_env_value(const char *name, char **env)
{
	int		len;
	char	*eq;
	int		i;

	i = 0;
	while (env[i])
	{
		eq = ft_strchr(env[i], '=');
		if (!eq)
		{
			i++;
			continue ;
		}
		len = eq - env[i];
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '='
				&& name[len] == '\0')
			return (eq + 1);
		i++;
	}
	return ("");
}

char	*expand_one_var(char **p, int last_status, char **env)
{
	const char	*start;
	int			len;
	char		*var_name;
	char		*value;

	start = *p + 1;
	if (*start == '?')
	{
		(*p) += 2;
		return (ft_itoa(last_status));
	}
	len = 0;
	while (start[len] && (ft_isalnum(start[len]) || start[len] == '_'))
		len++;
	if (len == 0)
		value = ft_substr(*p, 0, 1);
	else
	{
		var_name = ft_substr(start, 0, len);
		value = ft_strdup(get_env_value(var_name, env));
		free(var_name);
	}
	*p += len + 1;
	return (value);
}
