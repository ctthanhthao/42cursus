NAME = invalid

CC = cc
CCFLAGS = -Wall -Wextra -Werror

SRC = check_product_id2.c get_next_line_utils.c get_next_line.c \
		free_split.c ft_atoll.c ft_lltoa.c ft_lstadd_back.c \
		ft_lstclear.c ft_lstnew.c ft_memcmp.c ft_split.c \
		ft_substr.c
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