NAME = joltage

CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRC = joltage2.c get_next_line_utils.c get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re