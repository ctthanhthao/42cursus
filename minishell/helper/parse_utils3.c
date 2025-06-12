/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:13:44 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/05 15:19:07 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_memory_allc(int *capacity, int buf_i, char **buffer)
{
	char	*new_buf;

	new_buf = NULL;
	if (buf_i + 2 >= *capacity)
	{
		*capacity *= 2;
		new_buf = realloc(*buffer, *capacity);
		if (!new_buf)
		{
			free(*buffer);
			return (0);
		}
		*buffer = new_buf;
	}
	return (1);
}

int	grow_token_arr(char ***tokens, int *capacity, int used)
{
	char	**new_tokens;

	if (used + 2 >= *capacity)
	{
		if (*capacity * 2 > 1024)
		{
			ft_printf(R "C'mon Dude, this is the " BLUE "minishell_dude");
			ft_printf(RST R ", not a thesis!");
			ft_printf(" Try fewer args! Seriously, Bro! Be real!\n" RST);
			free_split(*tokens);
			*tokens = NULL;
			return (0);
		}
		*capacity *= 2;
		new_tokens = realloc(*tokens, (*capacity) * sizeof(char *));
		if (!new_tokens)
		{
			free(*tokens);
			*tokens = NULL;
			return (0);
		}
		*tokens = new_tokens;
	}
	return (1);
}

int	wrd_handle_quote(const char *input, int *i, t_bufinfo *buf)
{
	char	quote;

	quote = input[(*i)++];
	buf->buffer[buf->buf_i++] = quote;
	while (input[*i] && input[*i] != quote)
	{
		if (!token_memory_allc(&buf->capacity, buf->buf_i, &buf->buffer))
			return (0);
		buf->buffer[buf->buf_i++] = input[(*i)++];
	}
	if (input[*i] == quote)
		buf->buffer[buf->buf_i++] = input[(*i)++];
	return (1);
}
