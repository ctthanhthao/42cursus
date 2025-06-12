# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 11:16:13 by amarcz            #+#    #+#              #
#    Updated: 2024/11/04 16:24:32 by amarcz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  ft_striteri.c\
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isspace.c

PRINTF_SRC		=	ft_printf/ft_converthexa.c ft_printf/ft_flag_determin.c \
					ft_printf/ft_flags.c ft_printf/ft_printchar.c \
					ft_printf/ft_printdigits.c ft_printf/ft_printf.c \
					ft_printf/ft_printperc.c ft_printf/ft_printpointer.c \
					ft_printf/ft_printstring.c ft_printf/ft_printunsigned.c \
					ft_printf/ft_strlen.c
			
OBJS			= $(SRCS:.c=.o)

PRINTF_OBJ		= $(PRINTF_SRC:%c=%o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS) $(PRINTF_OBJ)
				ar rcs $(NAME) $(OBJS) $(PRINTF_OBJ)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			all

so:
				$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS) -shared -o libft.so

.PHONY:			all clean fclean re bonus