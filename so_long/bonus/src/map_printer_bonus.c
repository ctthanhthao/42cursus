/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 15:09:30 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == COLLECTIBLE || type == PLAYER || type == EXIT || type == EMPTY)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == COLLECTIBLE)
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.collectible, x, y);
	else if (type == PLAYER)
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player_down, x, y);
	else if (type == EXIT)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
	else if (type == WALL)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
	else if (type == ENEMY)
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.enemy, x, y);
}

void	map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
	x = 0;
	while (x <= map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL + IMG_PXL);
		x++;
	}
}
