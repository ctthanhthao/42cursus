NAME		= cub3D
BONUS_NAME	= cub3D_bonus

SRC_DIR		= src
OBJ_DIR		= objs
BOBJ_DIR	= objs/bonus
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# ── Mandatory sources ─────────────────────────────────────────────────────────
SRC_FILES	=	main.c \
				game/game.c \
				game/controls.c \
				game/init_mlx.c \
				game/key_hook.c \
				game/initialize.c \
				render/render.c \
				render/textures.c \
				render/ray.c \
				render/render_utils.c \
				utils/error.c \
				utils/common_utils.c \
				utils/log_mesg.c \
				utils/cleanup.c \
				parser/parse_map_utils.c parser/parse_map.c parser/parse_textures.c \
				parser/parse_colors.c parser/parser.c parser/read_lines.c \
				parser/parse_colors_utils.c parser/validate.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ── Bonus sources ─────────────────────────────────────────────────────────────
# Shared: all mandatory except the 5 files overridden by bonus versions
SHARED_FILES =	main.c \
				game/game.c \
				render/textures.c \
				render/ray.c \
				render/render_utils.c \
				utils/error.c \
				utils/common_utils.c \
				utils/log_mesg.c \
				utils/cleanup.c \
				parser/parse_map_utils.c parser/parse_map.c parser/parse_textures.c \
				parser/parse_colors.c parser/parser.c parser/read_lines.c \
				parser/parse_colors_utils.c parser/validate.c

BONUS_FILES	=	game/controls_bonus.c \
				game/key_hook_bonus.c \
				game/init_mlx_bonus.c \
				game/initialize_bonus.c \
				game/minimap_bonus.c \
				game/minimap_utils_bonus.c \
				game/minimap_border_bonus.c \
				render/render_bonus.c

SHARED_OBJ	= $(addprefix $(BOBJ_DIR)/, $(SHARED_FILES:.c=.o))
BONUS_OBJ	= $(addprefix $(BOBJ_DIR)/, $(BONUS_FILES:.c=.o))
ALL_BONUS_OBJ = $(SHARED_OBJ) $(BONUS_OBJ)

# ── Compiler ──────────────────────────────────────────────────────────────────
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a
LDLIBS		= $(LIBFT) $(MLX) -lXext -lX11 -lm

# ── Rules ─────────────────────────────────────────────────────────────────────
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR) CC="cc -Wno-strict-prototypes -Wno-return-type -Wno-parentheses -Wno-pointer-sign"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) $(LDLIBS) -o $(NAME)

$(BOBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(LIBFT) $(MLX) $(ALL_BONUS_OBJ)
	$(CC) $(ALL_BONUS_OBJ) $(LDLIBS) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
