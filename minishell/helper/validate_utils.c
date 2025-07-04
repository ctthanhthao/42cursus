/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:27:32 by amarcz            #+#    #+#             */
/*   Updated: 2025/07/04 15:41:33 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quoted(char *token)
{
	int	len;

	len = ft_strlen(token);
	if ((token[0] == '\'' && token[len - 1] == '\'')
		|| (token[0] == '\"' && token[len - 1] == '\"'))
		return (1);
	return (0);
}

int	is_redirection_in_quote(char *token)
{
	bool	in_single;
	bool	in_double;
	bool	in_quote;
	int		i;

	in_double = false;
	in_single = false;
	in_quote = true;
	i = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (token[i] == '\"' && !in_single)
			in_double = !in_double;
		if (token[i] == '<' || token[i] == '>')
		{
			if (!in_double && !in_single)
				in_quote = false;
			else
				in_quote = true;
		}
		i++;
	}
	return (in_quote);
}
