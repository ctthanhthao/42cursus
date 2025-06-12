/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:40:26 by thchau            #+#    #+#             */
/*   Updated: 2025/05/31 21:29:55 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*extract_key(const char *entry)
{
	char	*eq;

	eq = ft_strchr(entry, '=');
	if (eq)
		return (ft_substr(entry, 0, eq - entry));
	else
		return (ft_strdup(entry));
}

char	*strip_quotes(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if ((str[0] == '"' && str[len - 1] == '"')
		|| (str[0] == '\'' && str[len - 1] == '\''))
		return (ft_substr(str, 1, len - 2));
	return (ft_strdup(str));
}

int	check_valid_identifier(const char *s)
{
	if (!s || (!ft_isalpha(*s) && *s != '_'))
		return (log_errno("not a valid identifier"), CMD_FAILURE);
	while (*s && *s != '=')
	{
		if (!ft_isalnum(*s) && *s != '_')
			return (log_errno("not a valid identifier"), CMD_FAILURE);
		s++;
	}
	return (CMD_SUCCESS);
}
