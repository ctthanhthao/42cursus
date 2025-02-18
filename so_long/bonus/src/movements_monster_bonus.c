/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_monster_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/11 07:29:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	move_resume_monster(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (map->array[y][x] == 'P')
		return (ft_lose(map));
}

void	move_up_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->enemy.array[0][m];
	x = map->enemy.array[1][m];
	if (y > 0 && map->array[y - 1][x] != '1')
	{
		move_resume_monster(map, x, y, UP);
		if (map->array[y - 1][x] == 'E' || map->array[y - 1][x] == 'C'
			|| map->array[y - 1][x] == 'X' || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y--;
	}
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		x * IMG_PXL + 8, y * IMG_PXL);
	map->array[y][x] = 'X';
	map->enemy.array[0][m] = y;
}

void	move_left_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->enemy.array[0][m];
	x = map->enemy.array[1][m];
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		move_resume_monster(map, x, y, LEFT);
		if (map->array[y][x - 1] == 'E' || map->array[y][x - 1] == 'C'
			|| map->array[y][x - 1] == 'X' || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x--;
	}
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		x * IMG_PXL + 8, y * IMG_PXL);
	map->array[y][x] = 'X';
	map->enemy.array[1][m] = x;
}

void	move_down_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->enemy.array[0][m];
	x = map->enemy.array[1][m];
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		move_resume_monster(map, x, y, DOWN);
		if (map->array[y + 1][x] == 'E' || map->array[y + 1][x] == 'C'
			|| map->array[y + 1][x] == 'X' || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		y++;
	}
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		x * IMG_PXL + 8, y * IMG_PXL);
	map->array[y][x] = 'X';
	map->enemy.array[0][m] = y;
}

void	move_right_m(t_map *map, int m)
{
	int	x;
	int	y;

	y = map->enemy.array[0][m];
	x = map->enemy.array[1][m];
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_resume_monster(map, x, y, RIGHT);
		if (map->array[y][x + 1] == 'E' || map->array[y][x + 1] == 'C'
			|| map->array[y][x + 1] == 'X' || map->exit == 1)
			return ;
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		map->array[y][x] = '0';
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
		x * IMG_PXL, y * IMG_PXL);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
		x * IMG_PXL + 8, y * IMG_PXL);
	map->array[y][x] = 'X';
	map->enemy.array[1][m] = x;
}
