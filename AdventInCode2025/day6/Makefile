NAME = grandTotal

CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRC = grand_total1.c get_next_line_utils.c get_next_line.c free_3darr.c \
		ft_substr.c ft_split.c ft_isalnum.c ft_substr_custom.c
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