NAME = formexecution

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re