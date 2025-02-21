/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/20 22:25:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/*void	move_animation_right(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_right,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_left(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_left,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_up(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_up,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}

void	move_animation_down(t_map *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	if (map->z == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 1;
	}
	else if (map->z == 1)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_down,
			x * IMG_PXL + 8, y * IMG_PXL);
		map->z = 0;
	}
}*/

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

static void	player_move_horizon(t_map *map, int x, int y, enum DIR dir)
{
	map->moves++;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		(x + dir) * IMG_PXL, y * IMG_PXL);
	if (dir == LEFT && map->z == 0)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_left,
			(x - 1) * IMG_PXL, y * IMG_PXL);
	else if (dir == LEFT && map->z == 1)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_left,
			(x - 1) * IMG_PXL, y * IMG_PXL);
	else if (dir == RIGHT && map->z == 0)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_right,
			(x + 1) * IMG_PXL, y * IMG_PXL);
	else if (dir == RIGHT && map->z == 1)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_right,
			(x + 1) * IMG_PXL, y * IMG_PXL);
	map->array[y][x + dir] = PLAYER;
	print_movements(map);
}

static void	player_move_vertical(t_map *map, int x, int y, enum DIR dir)
{
	map->moves++;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, (y + dir) * IMG_PXL);
	if (dir == UP && map->z == 0)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_up,
			x * IMG_PXL, (y - 1) * IMG_PXL);
	else if (dir == UP && map->z == 1)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_keep_up,
			x * IMG_PXL, (y - 1) * IMG_PXL);
	else if (dir == DOWN && map->z == 0)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down,
			x * IMG_PXL, (y + 1) * IMG_PXL);
	else if (dir == DOWN && map->z == 1)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.player_down,
			x * IMG_PXL, (y + 1) * IMG_PXL);
	map->z ^= 1;
	map->array[y + dir][x] = PLAYER;
	print_movements(map);
}

void	move(t_map *map, char axis, enum DIR direction)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (axis == 'y' && y > 0 && y < map->y - 1)
	{
		if (map->array[y + direction][x] != WALL)
		{
			if (!check_move_in_array(map, x, y + direction))
				return ;
		}
		player_move_vertical(map, x, y, direction);
		map->player.y += direction;
	}
	else if (axis == 'x' && x > 0 && x < map->x - 1)
	{
		if (map->array[y][x + direction] != WALL)
		{
			if (!check_move_in_array(map, x + direction, y))
				return ;
		}
		player_move_horizon(map, x, y, direction);
		map->player.x += direction;
	}
}