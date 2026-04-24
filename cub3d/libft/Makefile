# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 13:49:01 by phofer            #+#    #+#              #
#    Updated: 2026/03/11 17:02:28 by phofer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC_DIR		= .
OBJ_DIR		= objs

SRC_FILES		=	ft_strlen.c ft_atoi.c ft_memchr.c ft_memcmp.c ft_strchr.c \
					ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c ft_memcpy.c \
					ft_memmove.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
					ft_isprint.c ft_toupper.c ft_tolower.c ft_strncmp.c ft_strlcpy.c \
					ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_strcmp.c ft_strcpy.c ft_strcat.c ft_strncpy.c ft_bubble_sort.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c \
					ft_printf_utils.c ft_printf_utils2.c libftprintf.c \
					get_next_line_utils.c get_next_line.c ft_isspace.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
