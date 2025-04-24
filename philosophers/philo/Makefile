NAME        	:= philo
CC          	:= cc
CFLAGS      	:= -Wall -Wextra -Werror -g -Iinclude
LIB_DIR 		:= lib
SRC_DIR			:= src

# Source Files (explicitly listed)
SRCS    := main.c \
		$(LIB_DIR)/getters_setters.c $(LIB_DIR)/getters_setters2.c  $(LIB_DIR)/log_msg.c \
		$(LIB_DIR)/safe_functions.c  $(LIB_DIR)/utils.c \
		$(SRC_DIR)/clean_up.c $(SRC_DIR)/one_philo.c $(SRC_DIR)/monitor.c       $(SRC_DIR)/dinner.c \
		$(SRC_DIR)/init.c     $(SRC_DIR)/parsing.c   $(SRC_DIR)/philo_actions.c $(SRC_DIR)/synchronize.c
	
OBJS        := $(SRCS:.c=.o)

# Header Files (for dependency tracking)
HEADERS     := include/philosopers.h

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