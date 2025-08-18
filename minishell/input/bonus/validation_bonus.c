/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:05:19 by thchau            #+#    #+#             */
/*   Updated: 2025/07/05 12:43:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static int	base_error(char **tokens)
{
	if (is_logical_op(tokens[0]) || (!ft_strncmp(tokens[0], "(", 2)
			&& tokens[1] && !ft_strncmp(tokens[1], ")", 2))
		|| !ft_strncmp(tokens[0], "\\", 2))
		return (ft_printf(R "Whoa, Dude!\n" RST),
			ft_printf(R "You can't start a command with '&&', '||', '|',"
				" '()' or '\\'.")
			, ft_printf(" Seriously, Bro!\n" RST), 0);
	return (1);
}

static int	operator_check(char **tokens, int i)
{
	if (!tokens[i + 1] || is_logical_op(tokens[i + 1])
		|| ft_strcmp(tokens[i + 1], ")") == 0)
		return (ft_printf(R "Yo, Bro!\n" RST),
			ft_printf(R "You've totally messed up"),
			ft_printf("the syntax at %s!\n" RST, tokens[i]), 0);
	return (1);
}

int	validate_tokens_bonus(char **tokens)
{
	int		i;

	i = 0;
	if (!tokens || !tokens[0])
		return (1);
	if (!base_error(&tokens[0]))
		return (0);
	while (tokens[i])
	{
		if (is_logical_op(tokens[i]))
		{
			if (!operator_check(tokens, i))
				return (0);
		}
		else if (!is_redirection_in_quote(tokens[i]))
		{
			if (!tokens[i + 1] || is_logical_op(tokens[i + 1])
				|| ft_is_redirection(tokens[i + 1]))
				return (ft_printf(R "Not cool, Dude!\n" RST),
					ft_printf(R "Syntax error near %s", tokens[i]),
					ft_printf("redirection, Bro!\n" RST), 0);
		}
		i++;
	}
	return (1);
}
