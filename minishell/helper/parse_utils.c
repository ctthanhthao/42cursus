/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:42:11 by amarcz            #+#    #+#             */
/*   Updated: 2025/07/04 15:49:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_curr(t_cmd **curr, int *argv_i, t_cmd **head, t_cmd **prev)
{
	if (!*curr)
	{
		*curr = malloc(sizeof(t_cmd));
		if (!*curr)
			return (0);
		(*curr)->argv = ft_calloc(1024, sizeof(char *));
		if (!(*curr)->argv)
			return (0);
		(*curr)->redirs = NULL;
		(*curr)->next = NULL;
		(*curr)->next_type = CMD_NONE;
		(*curr)->heredoc_fd = -1;
		*argv_i = 0;
		if (!*head)
			*head = *curr;
		else
			(*prev)->next = *curr;
	}
	return (1);
}

void	token_checker(t_cmd *curr, char *c)
{
	if (curr)
	{
		if (ft_strcmp(c, "||") == 0)
			curr->next_type = CMD_OR_IF;
		else if (ft_strcmp(c, "|") == 0)
			curr->next_type = CMD_PIPE;
		else if (ft_strcmp(c, "&&") == 0)
			curr->next_type = CMD_AND_IF;
	}
}

void	token_init(t_cmd **curr, t_cmd **prev, int *i, int argv_i)
{
	(*curr)->argv[argv_i] = NULL;
	(*i)++;
	*prev = *curr;
	*curr = NULL;
}

static int	handle_expansion(char **tokens, t_parse_state *s)
{
	char	**expanded;
	int		j;

	expanded = handle_expansion_if_any(tokens[s->i++], s->last_status,
			s->envp);
	if (expanded)
	{
		j = 0;
		while (expanded[j])
		{
			if (expanded[j][0] != '\0')
			{
				s->curr->argv[s->argv_i] = ft_strdup(expanded[j]);
				if (!s->curr->argv[s->argv_i])
				{
					free_split(expanded);
					return (-1);
				}
				s->argv_i++;
			}
			j++;
		}
		free_split(expanded);
	}
	return (1);
}

int	handle_token(char **tokens, t_parse_state *s)
{
	if (!init_curr(&s->curr, &s->argv_i, &s->head, &s->prev))
		return (0);
	if (is_logical_op(tokens[s->i]))
		return (token_checker(s->curr, tokens[s->i]),
			token_init(&s->curr, &s->prev, &s->i, s->argv_i), 2);
	if (!is_redirection_in_quote(tokens[s->i]))
	{
		if (!handle_redirection(s->curr, tokens, &s->i))
			return (-1);
		return (2);
	}
	return (handle_expansion(tokens, s));
}
