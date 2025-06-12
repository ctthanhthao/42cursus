/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:06:28 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/05 10:21:13 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	are_full_quotes(const char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 2)
		return (0);
	if ((s[0] == '\'' && s[len - 1] == '\'')
		|| (s[0] == '"' && s[len - 1] == '"'))
		return (1);
	return (0);
}

int	wildcard_check(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strchr(tokens[i], '*'))
		{
			if (ft_strchr(tokens[i], '\'') || ft_strchr(tokens[i], '\"'))
			{
				if (!are_full_quotes(tokens[i]))
				{
					ft_printf(R "Dude, WHAT IS THIS?!! ");
					ft_printf("You can't handle wildcards mixed");
					ft_printf(" with quotes like this: %s!\n" RST, tokens[i]);
					return (0);
				}
			}
		}
		i++;
	}
	return (1);
}

int	check_invalid_chars(const char *input)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (input[i])
	{
		if (input[i] == '\'' && in_double % 2 == 0)
			in_single++;
		else if (input[i] == '\"' && in_single % 2 == 0)
			in_double++;
		else if (input[i] == ';' && (in_single % 2 == 0 && in_double % 2 == 0))
			return (ft_printf(R "Whoa, Bro! TOTALLY not cool! "),
				ft_printf("The semicolon ';' is not supported in"),
				ft_printf(BLUE " minishell_dude" R "!\n" RST), 0);
		i++;
	}
	return (1);
}

int	check_unclosed_quotes(const char *input)
{
	int	i;
	int	single;
	int	dquote;

	i = 0;
	single = 0;
	dquote = 0;
	while (input[i])
	{
		if (input[i] == '\'' && dquote % 2 == 0)
			single++;
		else if (input[i] == '\"' && single % 2 == 0)
			dquote++;
		i++;
	}
	if ((single % 2 != 0 || single == 1) || (dquote % 2 != 0 || dquote == 1))
	{
		if (single % 2 != 0)
			return (ft_printf(R "Whoa, you messed up! You forgot to "),
				ft_printf("close a single quote, Dudio!\n" RST), 0);
		else
			return (ft_printf(R "Whoa! You forgot to close a double "),
				ft_printf("quote! Pay attention, Bro!\n" RST), 0);
	}
	return (1);
}

int	is_logical_op(char *token)
{
	return (ft_strcmp(token, "||") == 0
		|| ft_strcmp(token, "|") == 0 || ft_strcmp(token, "&&") == 0);
}
