NAME        	:= push_swap
BONUS_NAME 	    := checker
CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror -Iinclude
LIB_DIR 		:= lib
SORT_DIR 		:= sort
STACK_OPS_DIR 	:= stack_ops
BONUS_DIR 		:= bonus

# Source Files (explicitly listed)
SRCS        := ft_process.c push_swap.c \
    $(LIB_DIR)/common_utils.c $(LIB_DIR)/ft_alloc.c  $(LIB_DIR)/ft_error.c   $(LIB_DIR)/ft_free.c \
	$(LIB_DIR)/ft_split.c     $(LIB_DIR)/ft_strdup.c $(LIB_DIR)/ft_strlcpy.c $(LIB_DIR)/ft_strlen.c \
	$(LIB_DIR)/ft_strncmp.c   $(LIB_DIR)/ps_opslen.c $(LIB_DIR)/ps_strjoin.c \
	$(SORT_DIR)/sort_five.c  $(SORT_DIR)/sort_l_execution.c $(SORT_DIR)/sort_l_movement.c \
	$(SORT_DIR)/sort_three.c $(SORT_DIR)/sort_l_selection.c $(SORT_DIR)/sort_large.c \
    $(STACK_OPS_DIR)/ft_checkdup.c  $(STACK_OPS_DIR)/ft_min_max.c  $(STACK_OPS_DIR)/ft_stack_nals.c \
	$(STACK_OPS_DIR)/ft_stack_p.c   $(STACK_OPS_DIR)/ft_stack_r.c  $(STACK_OPS_DIR)/ft_stack_rr.c \
	$(STACK_OPS_DIR)/ft_stack_s.c   $(STACK_OPS_DIR)/ft_stack_free.c\

BONUS_SRC	:= ft_process.c \
	$(BONUS_DIR)/checker.c $(BONUS_DIR)/get_next_line.c \
	$(LIB_DIR)/common_utils.c $(LIB_DIR)/ft_alloc.c  $(LIB_DIR)/ft_error.c   $(LIB_DIR)/ft_free.c \
	$(LIB_DIR)/ft_split.c     $(LIB_DIR)/ft_strdup.c $(LIB_DIR)/ft_strlcpy.c $(LIB_DIR)/ft_strlen.c \
	$(LIB_DIR)/ft_strncmp.c   $(LIB_DIR)/ps_opslen.c $(LIB_DIR)/ps_strjoin.c $(LIB_DIR)/ft_strjoin.c\
	$(STACK_OPS_DIR)/ft_checkdup.c  $(STACK_OPS_DIR)/ft_stack_nals.c $(STACK_OPS_DIR)/ft_stack_s.c \
	$(STACK_OPS_DIR)/ft_stack_p.c   $(STACK_OPS_DIR)/ft_stack_r.c  $(STACK_OPS_DIR)/ft_stack_rr.c \
	$(STACK_OPS_DIR)/ft_stack_free.c\
	
OBJS        := $(SRCS:.c=.o)
BONUS_OBJS  := $(BONUS_SRC:.c=.o)

# Header Files (for dependency tracking)
HEADERS     := include/push_swap.h include/push_swap_bonus.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Executable $(NAME) created."

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "Executable $(BONUS_NAME) created."

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "Executable $(NAME) and $(BONUS_NAME) cleaned."

re: fclean all

# Dependencies
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	@echo "Running tests..."
	@./$(NAME) "2 1 3 6 5 8 4"
	@./$(NAME) 1 2 3 4 5 | wc -l
	@./$(NAME) 5 4 3 2 1 | wc -l
	@./$(NAME) 42 | wc -l
	@./$(NAME) "1 2 one" 2>> error_log.txt || echo "Error in handling invalid input"
	@echo "Tests completed."
	@echo "Error log contents:"
	@cat error_log.txt

.PHONY: all clean fclean re test

