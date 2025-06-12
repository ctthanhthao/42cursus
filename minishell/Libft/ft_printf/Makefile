# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:07:36 by amarcz            #+#    #+#              #
#    Updated: 2025/04/30 15:13:14 by amarcz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_converthexa.c \
					ft_printchar.c	\
					ft_printdigits.c \
					ft_printf.c	\
					ft_printperc.c \
					ft_printpointer.c \
					ft_printstring.c \
					ft_printunsigned.c \
					ft_strlen.c \
					ft_flags.c	\
					ft_flag_determin.c
OBJS			=	$(SRCS:.c=.o)

BONUS			=	ft_flag_determin.c \
					ft_flags.c
BONUS_OBJS		= 	$(BONUS:.c=.o)

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I.

NAME			= 	libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
						ar rcs $(NAME) $(OBJS)
clean:			
						$(RM) $(OBJS) $(BONUS_OBJS)
						
fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
						
.PHONY:			all clean fclean re