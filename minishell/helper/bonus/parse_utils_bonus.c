/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:45:36 by thchau            #+#    #+#             */
/*   Updated: 2025/06/10 12:50:50 by thchau           ###   ########.fr       */
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
