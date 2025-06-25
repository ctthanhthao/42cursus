/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:28:36 by thchau            #+#    #+#             */
/*   Updated: 2025/06/16 20:32:01 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell_bonus.h"

static int	handle_quotes(char *input, int *i)
{
	int	quote;

	quote = input[*i];
	while (input[*i] && input[*i] != quote)
		(*i)++;
	if (!input[*i])
	{
		ft_printf(R "Sry Dude, we changed our minds. :( ");
		ft_printf(R "We are lazy as DAMN...");
		ft_printf("so we don't support the unclosed quotes in the ");
		ft_printf(BLUE "minishell_dude" R ".\n" RST);
		return (0);
	}
	(*i)++;
	return (1);
}

static void	handle_operator(char *input, char **tokens, int *i, int *tokeni)
{
	int	start;

	start = *i;
	if (is_special(input[*i]) && input[*i] == input[*i + 1])
		*i += 2;
	else
		(*i)++;
	tokens[(*tokeni)++] = ft_substr(input, start, *i - start);
}

static void	handle_word(char *input, char **tokens, int *i, int *tokeni)
{
	t_bufinfo	buf;

	buf.capacity = 64;
	buf.buf_i = 0;
	buf.buffer = malloc(buf.capacity);
	if (!buf.buffer)
		return ;
	while (input[*i] && !(input[*i] == ' ' || input[*i] == '\t'
			|| is_special(input[*i]) || input[*i] == '(' || input[*i] == ')'))
	{
		if (!token_memory_allc(&buf.capacity, buf.buf_i, &buf.buffer))
			return ;
		if (input[*i] == '\'' || input[*i] == '\"')
		{
			if (!wrd_handle_quote(input, i, &buf))
				return ;
		}
		else
			buf.buffer[buf.buf_i++] = input[(*i)++];
	}
	buf.buffer[buf.buf_i] = '\0';
	tokens[(*tokeni)++] = buf.buffer;
}

static int	execute_tokens(char *input, int *i, char **tokens, int *tokeni)
{
	int	start;

	start = 0;
	if (input[*i] == '\'' || input[*i] == '\"')
	{
		start = *i;
		if (!(handle_quotes(input, i)))
			return (0);
		*i = start;
		handle_word(input, tokens, i, tokeni);
	}
	else if (is_special(input[*i]) || input[*i] == '(' || input[*i] == ')')
		handle_operator(input, tokens, i, tokeni);
	else
		handle_word(input, tokens, i, tokeni);
	return (1);
}

char	**ft_tokenize_bonus(char *input)
{
	char	**tokens;
	int		i;
	int		tokeni;
	int		capacity;

	tokeni = 0;
	capacity = 64;
	tokens = safe_alloc(capacity);
	if (!tokens)
		return (NULL);
	i = 0;
	if (!tokens)
		return (NULL);
	while (input[i])
	{
		i = skip_whitespace(input, i);
		if (!input[i])
			break ;
		if (!grow_token_arr(&tokens, &capacity, tokeni)
			|| !execute_tokens(input, &i, tokens, &tokeni))
			return (free_split(tokens), NULL);
	}
	return (token_ender(tokens, tokeni), tokens);
}
