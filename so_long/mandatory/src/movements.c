/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/23 11:01:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_move_in_array(t_map *map, int x, int y)
{
	if (map->array[y][x] == EXIT)
	{
		if (map->c == 0)
			ft_win(map);
		return (0);
	}
	if (map->array[y][x] == COLLECTIBLE)
	{
		map->array[y][x] = EMPTY;
		map->c--;
	}
	return (1);
}

static void	player_move_horizon(t_map *map, int x, int y, enum e_DIR dir)
{
	map->moves++;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	if (dir == LEFT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left,
			(x - 1) * IMG_PXL, y * IMG_PXL);
	else if (dir == RIGHT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right,
			(x + 1) * IMG_PXL, y * IMG_PXL);
	map->array[y][x + dir] = PLAYER;
}

static void	player_move_vertical(t_map *map, int x, int y, enum e_DIR dir)
{
	map->moves++;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	if (dir == UP)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up,
			x * IMG_PXL, (y - 1) * IMG_PXL);
	else if (dir == DOWN)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down,
			x * IMG_PXL, (y + 1) * IMG_PXL);
	map->array[y + dir][x] = PLAYER;
}

void	player_move(t_map *map, char axis, enum e_DIR direction)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (axis == 'y' && y > 0 && y < map->y
		&& map->array[y + direction][x] != WALL)
	{
		if (!check_move_in_array(map, x, y + direction) || map->exit == 1)
			return ;
		player_move_vertical(map, x, y, direction);
		map->player.y += direction;
	}
	else if (axis == 'x' && x > 0 && x < map->x - 1
		&& map->array[y][x + direction] != WALL)
	{
		if (!check_move_in_array(map, x + direction, y) || map->exit == 1)
			return ;
		player_move_horizon(map, x, y, direction);
		map->player.x += direction;
	}
}
