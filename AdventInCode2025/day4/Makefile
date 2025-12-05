NAME = paperrolls

CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRC = paperrolls2.c get_next_line_utils.c get_next_line.c free_split.c
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