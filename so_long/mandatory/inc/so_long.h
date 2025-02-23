/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/23 11:00:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define IMG_PXL 50
# define WND_NAME "so_long"
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1500
// Linux
enum e_KEY
{
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	ESC = 65307
};
// MacOs
/*enum e_KEY
{
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	ESC = 53
};*/

enum e_DIR
{
	UP = -1,
	DOWN = 1,
	LEFT = -1,
	RIGHT = 1
};

enum e_CHARACTERS
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

typedef struct s_player
{
	int	y;
	int	x;

}	t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*enemy;
}	t_img;

typedef struct s_map
{
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;
}	t_map;

char	*sl_strjoin(char *s1, char const *s2);
void	map_validator(t_map *map);
void	build_map_array(t_map *mapper);
void	file_to_image(t_map *mapper);
void	map_printer(t_map *mapper);
int		key_hook(int keycode, t_map *map);

void	error_filename(void);
void	error_wall(t_map *map);
void	error_openfile(char *filename);
void	error_shape(t_map *map, char *msg);
void	error_program(char *msg);
void	error_path(t_map *map);
void	error_map_elements(t_map *map);

void	ft_clean_up(t_map *map);
void	ft_free_array(char ***ret);

void	player_move(t_map *map, char axis, enum e_DIR direction);

void	ft_win(t_map *map);
int		ft_close(t_map *map);

void	print_movements(t_map *map);

void	validate_path(t_map *map);
void	locate_player(t_map *map);
#endif
