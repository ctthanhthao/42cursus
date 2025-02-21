/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 15:06:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	check_ahead_move(t_map *map, int x, int y)
{
	if (map->array[y][x] == PLAYER)
	{
		ft_lose(map);
		return (0);
	}
	if (map->array[y - 1][x] == EXIT || map->array[y - 1][x] == COLLECTIBLE
			|| map->array[y - 1][x] == ENEMY || map->exit == 1)
		return (0);
	return (1);
}

static void	enemy_move_horizon(t_map *map, int x, int y, enum e_DIR dir)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		(x + dir) * IMG_PXL, y * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		(x + dir) * IMG_PXL, y * IMG_PXL);
	map->array[y][x + dir] = ENEMY;
}

static void	enemy_move_vertical(t_map *map, int x, int y, enum e_DIR dir)
{
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	map->array[y][x] = EMPTY;
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, (y + dir) * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		x * IMG_PXL, (y + dir) * IMG_PXL);
	map->array[y + dir][x] = ENEMY;
}

void	enemy_move(t_map *map, char axis, enum e_DIR direction, int enemyth)
{
	int	x;
	int	y;

	y = map->enemy.array[0][enemyth];
	x = map->enemy.array[1][enemyth];
	if (axis == 'y' && y > 0 && y < map->y
		&& map->array[y + direction][x] != WALL)
	{
		if (!check_ahead_move(map, x, y + direction))
			return ;
		enemy_move_vertical(map, x, y, direction);
		map->enemy.array[0][enemyth] = y + direction;
	}
	else if (axis == 'x' && x > 0 && x < map->x
		&& map->array[y][x + direction] != WALL)
	{
		if (!check_ahead_move(map, x + direction, y))
			return ;
		enemy_move_horizon(map, x, y, direction);
		map->enemy.array[1][enemyth] = x + direction;
	}
}
