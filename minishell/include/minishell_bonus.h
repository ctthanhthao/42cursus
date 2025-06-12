/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:03:24 by thchau            #+#    #+#             */
/*   Updated: 2025/06/12 16:59:01 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include "minishell.h"

# define COLOR_CMD     "\033[1;34m"
# define COLOR_OP      "\033[1;33m"
# define COLOR_GROUP   "\033[1;35m"
# define COLOR_REDIR   "\033[0;32m"
# define COLOR_RESET   "\033[0m"

# define INITIAL_CAPACITY 32

typedef enum e_node_type
{
	NODE_AND,
	NODE_OR,
	NODE_PIPE,
	NODE_CMD,
	NODE_GROUP
}	t_node_type;

typedef struct s_ast
{
	t_node_type		type;
	struct s_ast	*left;
	struct s_ast	*right;
	t_cmd			*cmd;	// only used if type == NODE_CMD
	t_redir			*redirs;	// attach redirections to group or pipeline
}	t_ast;

typedef struct s_parser
{
	char	**tokens;
	int		tokeni;
	int		token_count; // total number of tokens
	char	**envp;
	int		last_status;
}	t_parser;

// Parser
t_ast	*parse_input_bonus(char *input, int last_status, char **envp);
t_ast	*parse_expression(t_parser *p);
t_ast	*parse_group_or_command(t_parser *p);
void	parse_redirections_bonus(t_redir **re, t_parser *p);
char	**ft_tokenize_bonus(char *input);
int		handle_expansion_bonus(char ***argv_ptr, int *argc, int *capacity,
			t_parser *p);
char	**extent_argv_if_need(char **argv, int *capacity, int argc);
// Executor
int		execute_ast(t_ast *node, int *last_status, char ***envp);
int		execute_cmd(t_cmd *cmd, int *last_status, char ***envp);
int		execute_pipe(t_ast *left, t_ast *right, int *last_status, char ***envp);
int		execute_group(t_ast *node, int *last_status, char ***envp);
// Utils
char	**safe_realloc(char **argv, int old_size, int new_size);
t_ast	*new_ast_node(t_node_type type, t_ast *left, t_ast *right, t_cmd *cmd);
t_redir	*new_redirections(t_token type, char *filename);
int		check_unclosed_parenthesis(const char *input);
void	free_redirs(t_redir *re);
void	free_ast(t_ast *node);
void	print_ast(t_ast *root);
void	print_redirections(t_ast *node, const char *prefix);
char	*node_type_str(t_node_type type);

#endif