#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#	 __  __    __    _  _  ____  ____  ____  __    ____ 		    	 	 #
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)		   		     #
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__) 		     		 #
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____) 𝕓𝕪 𝕁𝕠𝕤𝕖𝕡𝕙 ℂ𝕙𝕖𝕖𝕝       #									
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──CMD───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g $(SYSTEM)

# System Detection
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS =  -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅DIRECTORIES✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

MDT_DIR		=	mandatory/
BONUS_DIR	=	bonus/

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

LIBFT		=	libft/libft.a

INC			=	$(addprefix $(MDT_DIR), $(INC_DIR))

INC_BONUS	=	$(addprefix $(BONUS_DIR), $(INC_DIR)) 

INCLUDE		+= -I $(INC) 
INCLUDE		+= -I $(INC_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─SORCES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

SL_SRCS	=		so_long.c validate_path.c validators.c end_screen.c \
				errors1.c errors2.c file_to_image.c ft_free.c \
				build_map_array.c key_hook.c sl_strjoin.c \
				map_printer.c movements.c
				
SL_SRCS_BONUS	=	build_map_array_bonus.c end_screen_bonus.c enemies_movements_bonus.c \
					enemies_animation_bonus.c errors1_bonus.c errors2_bonus.c \
					file_to_image_bonus.c ft_free_bonus.c key_hook_bonus.c \
					map_printer_bonus.c player_animation_bonus.c \
					scan_enemies_bonus.c sl_strjoin_bonus.c so_long_bonus.c \
					validate_path_bonus.c validators_bonus.c

SRCS			+=	$(addprefix $(MDT_DIR), $(addprefix $(SRC_DIR), $(SL_SRCS)))
SRCS_BONUS		+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(SL_SRCS_BONUS)))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))
DEPS_BONUS		+=	$(addsuffix .d, $(basename $(OBJS_BONUS)))

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅───OBJECT DEPENDENCY TARGET───❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(OBJ_DIR)%.o : %.c Makefile
	@$(MD) $(dir $@)
	@make -sC mlx
	@make -sC libft
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) $(INCLUDE) -Imlx   $< -o $@ 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─TARGET─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS)  $(LIBFT) $(OBJS) -o $(NAME) $(MLXFLAGS)
			@echo "Moving libmlx.dylib..."
			@if [ -f mlx/libmlx.dylib ]; then mv mlx/libmlx.dylib ./; fi
			@echo "$(OK_COLOR)So Long Compiled!$(NO_COLOR)"

bonus:		$(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			@$(CC) $(CFLAGS)  $(LIBFT) $(OBJS_BONUS) -o $(NAME_BONUS) $(MLXFLAGS)
			@echo "Moving libmlx.dylib..."
			@if [ -f mlx/libmlx.dylib ]; then mv mlx/libmlx.dylib ./; fi
			@echo "$(OK_COLOR)So Long Bonus Compiled!$(NO_COLOR)"
clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@echo "Deleting libmlx.dylib..."
			@if [ -f libmlx.dylib ]; then $(RM) libmlx.dylib; fi
			@echo "$(OK_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -sC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(OK_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all


-include $(DEPS)
-include $(DEPS_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○IGNORE○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

.PHONY: all bonus clean fclean re 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NO_COLOR		=	\033[0m
OK_COLOR		=	\033[32;01m



