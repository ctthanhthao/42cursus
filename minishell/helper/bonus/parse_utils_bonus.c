/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:45:36 by thchau            #+#    #+#             */
/*   Updated: 2025/07/04 20:57:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

int	check_unclosed_parenthesis(const char *input)
{
	bool	in_single;
	bool	in_double;
	int		i;
	int		brackets;

	in_single = false;
	in_double = false;
	i = 0;
	brackets = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (input[i] == '\"' && !in_single)
			in_double = !in_double;
		else if (!in_double && !in_single && input[i] == '(')
			brackets++;
		else if (!in_double && !in_single && input[i] == ')')
			brackets--;
		i++;
	}
	if (brackets != 0)
		return (ft_printf(R "Whoa, you messed up! You forgot to "),
			ft_printf("close all parenthesises, Dudio!\n" RST), 0);
	return (1);
}

int	is_logical_op_bonus(char *token)
{
	return (ft_strcmp(token, "||") == 0
		|| ft_strcmp(token, "|") == 0 || ft_strcmp(token, "&&") == 0
		|| ft_strcmp(token, ")") == 0);
}

char	*create_syntax_err_msg(char *token)
{
	char	*er_msg;

	er_msg = ft_strdup("syntax error near unexpected token '");
	er_msg = ft_strjoin_free(er_msg, token);
	er_msg = ft_strjoin_free(er_msg, "'");
	return (er_msg);
}

bool	contain_invalid_parenthesis(char *argv1, char *argv2)
{
	char	*er_msg;

	if (ft_strcmp(argv1, "(") == 0)
	{
		if (argv2)
			er_msg = create_syntax_err_msg(argv2);
		else
			er_msg = create_syntax_err_msg("newline");
		log_errno(er_msg);
		free(er_msg);
		return (true);
	}
	return (false);
}
