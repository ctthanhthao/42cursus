/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:35:36 by thchau            #+#    #+#             */
/*   Updated: 2025/05/05 11:36:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// ===============================
// ENUMS
// ===============================
typedef enum e_redir_type
{
    REDIR_IN,      // <
    REDIR_OUT,     // >
    REDIR_APPEND,  // >>
    REDIR_HEREDOC  // <<
}   t_redir_type;

// ===============================
// STRUCTS
// ===============================
typedef struct s_redir
{
    t_redir_type     type;
    char            *filename;  // or delimiter for heredoc
    struct s_redir  *next;
}   t_redir;

typedef struct s_cmd
{
    char          **argv;       // arguments passed to execve or builtin
    t_redir        *redirs;     // list of redirections
    struct s_cmd   *next;       // next command in pipeline
}   t_cmd;

// ===============================
// PARSER INTERFACE
// ===============================
t_cmd   *parse_input(const char *line, char **envp);
char    **tokenize_line(const char *line);                            // optional internal
t_cmd   *build_cmd_list(char **tokens, char **envp);                 // optional internal
t_redir *parse_redirections(char **tokens, int *i);                  // optional internal

// ===============================
// EXECUTOR INTERFACE
// ===============================
int     execute_commands(t_cmd *cmd_list, char **envp);
int     is_builtin(const char *cmd);
int     execute_builtin(t_cmd *cmd, char ***envp);
void    apply_redirections(t_redir *redirs);

// ===============================
// CLEANUP / UTILS
// ===============================
void    free_cmd_list(t_cmd *cmd_list);
void    free_split(char **arr);

#endif