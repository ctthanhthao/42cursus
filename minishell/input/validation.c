/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:09:11 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/16 19:49:10 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *token)
{
	return (ft_strncmp(token, "||", 2) == 0
		|| ft_strncmp(token, "&&", 2) == 0
		|| ft_strncmp(token, "|", 1) == 0);
}

int	ft_is_redirection(char *token)
{
	return (ft_strncmp(token, ">>", 2) == 0
		|| ft_strncmp(token, ">", 1) == 0
		|| ft_strncmp(token, "<<", 2) == 0
		|| ft_strncmp(token, "<", 1) == 0);
}

int	base_error(char **tokens)
{
	if (is_operator(tokens[0]) || (!ft_strncmp(tokens[0], "(", 2)
			&& tokens[1] && !ft_strncmp(tokens[1], ")", 2))
		|| !ft_strncmp(tokens[0], "\\", 2))
		return (ft_printf(R "Whoa, Dude!\n" RST),
			ft_printf(R "You can't start a command with '&&', '||', '|',"
				" '()' or '\\'.")
			, ft_printf(" Seriously, Bro!\n" RST), 0);
	return (1);
}

int	operator_check(char **tokens, int i)
{
	if (!tokens[i + 1] || is_operator(tokens[i + 1]))
		return (ft_printf(R "Yo, Bro!\n" RST),
			ft_printf(R "You've totally messed up"),
			ft_printf("the syntax at %s!\n" RST, tokens[i]), 0);
	return (1);
}

int	validate_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens || !tokens[0])
		return (1);
	if (!base_error(&tokens[0]))
		return (0);
	while (tokens[i])
	{
		if (is_operator(tokens[i]))
		{
			if (!operator_check(tokens, i))
				return (0);
		}
		else if (is_redirection(tokens[i]) && !is_quoted(tokens[i]))
		{
			if (!tokens[i + 1] || is_operator(tokens[i + 1])
				|| ft_is_redirection(tokens[i + 1]))
				return (ft_printf(R "Not cool, Dude!\n" RST),
					ft_printf(R "Syntax error near %s", tokens[i]),
					ft_printf("redirection, Bro!\n" RST), 0);
		}
		i++;
	}
	return (1);
}
