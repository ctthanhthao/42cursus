/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:38:33 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/05 15:17:27 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_whitespace(const char *input, int i)
{
	while (input[i] == ' ' || input[i] == '\t')
		i++;
	return (i);
}

void	token_ender(char **tokens, int tokeni)
{
	tokens[tokeni] = NULL;
}

//IDENTIFY TOKEN
t_token	identify_tok(char *str)
{
	if (ft_strncmp(str, "||", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (REDIR_OUT);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (REDIR_OUT_APPEND);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (REDIR_IN);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (REDIR_HEREDOC);
	else if (ft_strncmp(str, "&&", 2) == 0)
		return (AND);
	else if (ft_strncmp(str, "|", 1) == 0)
		return (OR);
	return (WORD);
}

int	is_special(char c)
{
	return (c == '>' || c == '<' || c == '&' || c == '|');
}
