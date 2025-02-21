/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_monster_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:14:59 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 08:43:24 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	randomize_enemy(t_map *map, int m)
{
	if (map->enemy.pos == 0)
	{
		move_right_m(map, m);
		map->enemy.pos++;
	}
	else if (map->enemy.pos == 1)
	{
		move_down_m(map, m);
		map->enemy.pos++;
	}
	else if (map->enemy.pos == 2)
	{
		move_left_m(map, m);
		map->enemy.pos++;
	}
	else if (map->enemy.pos == 3)
	{
		move_up_m(map, m);
		map->enemy.pos++;
	}
	else
		map->enemy.pos = 0;
}

static void	monster_animation(t_map *map, int x, int y)
{
	if (map->action % 1000 == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy,
			x * IMG_PXL, y * IMG_PXL);
	}
	if (map->action % 3000 == 0)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy_flip,
			x * IMG_PXL, y * IMG_PXL);
	}
}

int	move_monster(t_map *map)
{
	int	m;
	int	x;
	int	y;

	m = 0;
	if (map->exit == 1)
		return (0);
	while (m < map->enemy.nbr)
	{
		y = map->enemy.array[0][m];
		x = map->enemy.array[1][m];
		monster_animation(map, x, y);
		if (map->action % 5000 == 0)
			randomize_enemy(map, m);
		m++;
	}
	map->action++;
	return (0);
}
