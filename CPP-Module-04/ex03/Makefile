NAME = interface

CXX = c++
CXXFLAG = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp \
		Ice.cpp MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
