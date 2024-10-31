NAME			= libftprintf.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDE 		= -I ./include
INCLUDE_BONUS 	= -I ./bonus
AR				= ar rcs
RM				= rm -f

SRCS			= ft_printf.c \
				./src/ft_printnumbers.c ./src/ft_process.c
SRCS_OBJS		= $(SRCS:.c=.o)

BONUS			= ft_printf.c \
				./bonus/ft_handlechars_bonus.c ./bonus/ft_handlehex_bonus.c \
				./bonus/ft_handlenum_bonus.c ./bonus/ft_handleptr_bonus.c \
				./bonus/ft_parseflags_bonus.c ./bonus/ft_process_bonus.c \
				./bonus/ft_handlenum_helper_bonus.c \
				./bonus/ft_handlehex_helper_bonus.c
BONUS_OBJS		= $(BONUS:.c=.o)

LIBS			= ./lib/ft_atoi.c ./lib/ft_isdigit.c ./lib/ft_itoa.c \
				./lib/ft_memset.c ./lib/ft_printchars.c ./lib/ft_strdup.c \
				./lib/ft_strlen.c ./lib/ft_strreverse.c ./lib/ft_utils.c
LIBS_OBJS		= $(LIBS:.c=.o)

# Rules
all: $(NAME)

# Create the library from mandatory object files
$(NAME): $(LIBS_OBJS) $(SRCS_OBJS)
	$(AR) $(NAME) $(LIBS_OBJS) $(SRCS_OBJS)

# Bonus rule - compile both mandatory and bonus object files
bonus: $(LIBS_OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(LIBS_OBJS) $(BONUS_OBJS)

# Complie .o files from .c files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_BONUS) -c $< -o $@

clean:
	$(RM) $(SRCS_OBJS) $(BONUS_OBJS) $(LIBS_OBJS) 

fclean: clean
	$(RM) $(NAME) $(BONUS_OBJS)

re: fclean all

.PHONY: all clean fclean re