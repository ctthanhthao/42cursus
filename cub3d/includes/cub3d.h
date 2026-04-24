/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:04:28 by phofer            #+#    #+#             */
/*   Updated: 2026/04/22 14:09:09 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//=========================================================
//========== GAME CONTROLS | CHANGE SPEED HERE=============
//=========================================================

# define WALL_MARGIN 0.15

# define MOVE_SPEED 0.05
# define ROT_SPEED  0.009

# define MOUSE_SENSITIVITY  0.003

//=========================================================

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define SUCCESS 1
# define FAILURE -1

typedef enum e_direction
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}	t_direction;

# define MINIMAP_SIZE  200
# define WIDTH      1280
# define HEIGHT     720

/* ── Key codes ─────────────────────────────────────────────────────────── */
# define KEY_ESC   65307
# define KEY_W     119
# define KEY_S     115
# define KEY_A     97
# define KEY_D     100
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define KEY_TAB	65289

/* ── keys_held bitmask flags ────────────────────────────────────────────── */
# define BIT_W      1
# define BIT_S      2
# define BIT_A      4
# define BIT_D      8
# define BIT_LEFT   16
# define BIT_RIGHT  32

/* ── X11 event codes and masks ─────────────────────────────────────────── */

# define EVENT_KEYPRESS     2
# define EVENT_KEYRELEASE   3
# define EVENT_MOUSEDOWN    4
# define EVENT_MOUSEUP      5
# define EVENT_MOUSEMOVE    6
# define EVENT_DESTROY      17

# define MASK_KEYPRESS      1
# define MASK_KEYRELEASE    2
# define MASK_MOUSEMOVE     64

/* ── Texture indices ───────────────────────────────────────────────────── */
# define TEX_NO  0
# define TEX_SO  1
# define TEX_WE  2
# define TEX_EA  3
# define TEX_COUNT 4

/* ── Colors ────────────────────────────────────────────────────────────── */
# define BLACK      0x000000
# define WHITE      0xFFFFFF
# define RED        0xFF0000
# define GREEN      0x00FF00
# define BLUE       0x0000FF
# define YELLOW     0xFFFF00
# define CYAN       0x00FFFF
# define MAGENTA    0xFF00FF

# define GREY_DARK  0x333333
# define GREY_MID   0x888888
# define GREY_LIGHT 0xCCCCCC

# define SKY_BLUE   0x87CEEB
# define DIRT_BROWN 0x654321

/* ── Structs ────────────────────────────────────────────────────────────── */
typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		minimap;
	t_img		textures[TEX_COUNT];
	char		*texture_path[TEX_COUNT];
	t_map		map;
	t_player	player;
	int			floor_color;
	int			ceiling_color;
	int			keys_held;
	double		mouse_delta_x;
	int			mouse_centered;
	int			mouse_enabled;
}	t_game;

/* ── Function prototypes ────────────────────────────────────────────────── */

/* lifecycle */
void	start_game(t_game *game, char *map);
void	init_game(t_game *game, char *map_path);
void	init_mlx(t_game *game);
int		close_game(t_game *game);
void	fatal_error(t_game *game, const char *msg);

/* render */
int		render(t_game *game);
void	cast_ray(t_game *game, t_ray *ray, int x);
void	draw_background(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
void	dda_step(t_ray *ray);

/* textures */
int		load_textures(t_game *game);

/* input */
int		key_hook(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	handle_movement(t_game *game);
int		mouse_move(int x, int y, t_game *game);
void	rotate_player(t_player *p, double angle);

/* testing */
void	init_game_test(t_game *game, char *map_path);

/* parsing */
char	**read_file_lines(const char *filename, int *line_count);
int		parse_file(t_game *game, const char *filename);
void	free_arr(char **arr);
char	*ft_trim(const char *str);
int		ft_arrlen(char **arr);

void	log_err(char *error_msg);
void	initialize(t_game *game);
void	cleanup(t_game *game);

#endif
