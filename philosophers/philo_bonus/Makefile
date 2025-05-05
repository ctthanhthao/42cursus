NAME        	:= philo_bonus
CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror -g -Iinclude
LIB_DIR 		:= lib
SRC_DIR			:= src

# Source Files (explicitly listed)
SRCS    := main.c \
		$(LIB_DIR)/log_msg.c $(LIB_DIR)/safe_functions.c  $(LIB_DIR)/safe_functions2.c $(LIB_DIR)/utils.c \
		$(LIB_DIR)/ft_itoa.c $(LIB_DIR)/ft_strjoin.c      $(LIB_DIR)/ft_strdup.c 		$(LIB_DIR)/getters.c \
		$(SRC_DIR)/clean_up.c $(SRC_DIR)/one_philo_process.c      $(SRC_DIR)/monitor.c  $(SRC_DIR)/dinner.c \
		$(SRC_DIR)/init.c     $(SRC_DIR)/multi_philo_processes.c  $(SRC_DIR)/philo_actions.c $(SRC_DIR)/parsing.c
	
OBJS        := $(SRCS:.c=.o)

# Header Files (for dependency tracking)
HEADERS     := include/philosopers_bonus.h

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