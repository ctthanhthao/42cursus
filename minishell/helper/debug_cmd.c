/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:01:15 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 16:36:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

const char	*token_to_str(t_token type)
{
	if (type == REDIR_IN)
		return ("<");
	else if (type == REDIR_OUT)
		return (">");
	else if (type == REDIR_HEREDOC)
		return ("<<");
	else if (type == REDIR_OUT_APPEND)
		return (">>");
	else
		return ("UNKNOWN");
}

const char	*cmd_type_to_str(t_cmd_type type)
{
	if (type == CMD_NONE)
		return ("NONE");
	else if (type == CMD_AND_IF)
		return ("AND_IF");
	else if (type == CMD_OR_IF)
		return ("OR_IF");
	else if (type == CMD_PIPE)
		return ("PIPE");
	else
		return ("UNKNOWN");
}

void	debug_redirs(t_redir *r)
{
	while (r)
	{
		printf("    Redirection: type=%s, filename='%s'\n",
			token_to_str(r->type), r->filename);
		r = r->next;
	}
}

void	debug_cmd(t_cmd *cmd)
{
	int	i;

	while (cmd)
	{
		printf("Command:\n");
		if (cmd->argv)
		{
			i = 0;
			while (cmd->argv[i])
			{
				printf("  argv[%d] = '%s'\n", i, cmd->argv[i]);
				i++;
			}
		}
		else
			printf("  argv = (null)\n");
		if (cmd->redirs)
			debug_redirs(cmd->redirs);
		else
			printf("  No redirections\n");
		printf("  next_type = %s\n", cmd_type_to_str(cmd->next_type));
		cmd = cmd->next;
		printf("\n");
	}
}
