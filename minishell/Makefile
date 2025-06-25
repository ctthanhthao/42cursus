NAME        	:= minishell
BONUS_NAME  	:= minishell_bonus
CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror -g -Iinclude
LDFLAGS 		:= -lreadline


# Source Files (explicitly listed)
SRCS    := helper/utils.c 			helper/cleanup.c 	 helper/clone.c 	   helper/sort.c 	helper/ms_ft_strjoin.c  \
			helper/main_utils.c 	helper/parse_utils.c helper/parse_utils2.c helper/tokenizer_utils.c \
			helper/validate_utils.c helper/export_utils.c helper/parse_utils3.c helper/debug_cmd.c helper/safe_func.c \
			helper/executor_utils.c \
			input/validation.c       input/parse.c       		input/tokenizer.c 		  input/redir_parse.c \
			input/handle_expansion.c input/expand_variables1.c  input/expand_variables2.c input/signal.c \
			input/expand_wildcard.c  \
			builtins/cd.c     builtins/echo.c builtins/env.c \
			builtins/export.c builtins/pwd.c  builtins/unset.c builtins/exit.c \
			executor/execute_builtin.c      executor/apply_redirections.c executor/execute_commands.c \
			executor/execute_sgl_command.c	executor/process_heredoc.c    executor/process_pipe.c \
			executor/backup_restore_redirections.c 
MAIN_SRC := main.c
OBJ        := $(SRCS:.c=.o) $(MAIN_SRC:.c=.o)

# Bonus source files
BONUS_SRCS 		:= helper/bonus/cleanup_bonus.c helper/bonus/parse_utils_bonus.c         helper/bonus/print_ast_bonus.c \
					helper/bonus/utils_bonus.c  helper/bonus/print_redirections_bonus.c \
					input/bonus/parse_bonus.c     input/bonus/parse_redirections_bonus.c input/bonus/parse_to_ast_bonus.c \
					input/bonus/tokenizer_bonus.c input/bonus/handle_expansion_bonus.c   input/bonus/parse_group_cmd.c \
					executor/bonus/execute_ast_bonus.c executor/bonus/execute_cmd_bonus.c executor/bonus/execute_group_bonus.c \
					executor/bonus/execute_pipe_bonus.c executor/bonus/apply_redirections_bonus.c executor/bonus/preprocess_heredoc_bonus.c
MAIN_BONUS_SRC 	:= main_bonus.c
BONUS_OBJ  		:= $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o) $(MAIN_BONUS_SRC:.c=.o)

#LIBFT

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

#FT_PRINTF

PRINTF_DIR = Libft/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCLUDES = -I$(LIBFT_DIR)

#COLORS:
GREEN = \033[1;32m
DEFAULT = \033[0m

$(NAME): submodules $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN) [minishell] Welcome to the minishell - Dude version, Dude!$(DEFAULT)"

$(BONUS_NAME): submodules $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(BONUS_NAME) $(LDFLAGS)
	@echo "$(GREEN) [minishell BONUS] You got the bonus features, Dude!$(DEFAULT)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

bonus: $(BONUS_NAME)

submodules:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GREEN) Everything is cleaned, Dude!$(DEFAULT)"

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GREEN) Everything is fully cleaned, Dude!$(DEFAULT)"

re: fclean all
	@echo "$(GREEN) Rebuild is done, Dude!$(DEFAULT)"

.PHONY: all clean fclean re bonus