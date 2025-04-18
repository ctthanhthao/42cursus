NAME        	:= philo
CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror -g -Iinclude

# Source Files (explicitly listed)
SRCS    := dinner.c getters_setters.c init.c  log_msg_error.c \
			parsing.c philo_actions.c safe_functions.c utils.c \
			main.c clean_up.c
	
OBJS        := $(SRCS:.c=.o)

# Header Files (for dependency tracking)
HEADERS     := philosopers.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread
	@echo "Executable $(NAME) created."

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable $(NAME) cleaned."

re: fclean all

# Dependencies
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re