/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:36:53 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/17 06:23:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	clean_up(char **tokens, t_parse_state *s)
{
	if (tokens)
		free_split(tokens);
	if (s->head)
		free_cmd(s->head);
	if (s->curr && s->curr != s->prev)
	{
		if (s->curr->argv)
			free_split(s->curr->argv);
		free(s->curr);
	}
}

void	initialize_state(t_parse_state *s, int argv_i,
		int last_status, char **envp)
{
	s->i = 0;
	s->argv_i = argv_i;
	s->curr = NULL;
	s->head = NULL;
	s->prev = NULL;
	s->last_status = last_status;
	s->envp = envp;
}

t_cmd	*token_loop(char **tokens, int argv_i, int last_status, char **envp)
{
	t_parse_state	s;
	int				ret;
	t_cmd			*result;

	ret = 0;
	result = NULL;
	initialize_state(&s, argv_i, last_status, envp);
	while (tokens[s.i])
	{
		ret = handle_token(tokens, &s);
		if (ret == -1 || ret == 0)
			return (clean_up(tokens, &s), NULL);
		if (ret == 2)
			continue ;
	}
	if (s.curr)
		s.curr->argv[s.argv_i] = NULL;
	s.prev = s.curr;
	if (s.head)
		result = clone_cmd(s.head);
	clean_up(NULL, &s);
	return (result);
}

t_cmd	*parse_input(char *input, int last_status, char **envp)
{
	char	**tokens;
	int		argv_i;
	t_cmd	*head;

	if (!check_unclosed_quotes(input) || !check_invalid_chars(input))
		return (NULL);
	tokens = ft_tokenize(input);
	if (!validate_tokens(tokens) || !tokens || !wildcard_check(tokens))
		return (free_split(tokens), NULL);
	argv_i = 0;
	head = token_loop(tokens, argv_i, last_status, envp);
	if (!head)
		return (free_split(tokens), NULL);
	free_split(tokens);
	return (head);
}

//DEBUG FUNCTION TO PRINT TOKENS:

// void print_cmds(t_cmd *cmd)
// {
//     const char  *token_names[] = {
//         "CMD", "WORD", "PIPE", "MORE", "MOREMORE", "LESS", "LESSLESS",
//         "AND", "OR"
//     };
//     const char *cmd_type_strs[] = {"NONE", "AND_IF", "OR_IF", "PIPE"};
//     int i;
//     t_redir *r;

//     i = -1;
//     while (cmd)
//     {
//         ft_printf("==== Command === \n");

//         if (cmd->argv)
//         {
//             while (cmd->argv[++i])
//             {
//                 ft_printf("Arg[%d]: %s\n", i, cmd->argv[i]);
//             }
//             ft_printf("Next type value: %d\n", cmd->next_type);
//             ft_printf("Next type: %s\n", cmd_type_strs[cmd->next_type]);
//         }
//         r = cmd ->redirs;
//         while (r)
//         {
//             ft_printf("Redir: %-10s | Type: %s\n", r->filename,
//             		token_names[r->type]);
//             r = r->next;
//         }
//         cmd = cmd->next;
//         i = -1;
//     }
// }
