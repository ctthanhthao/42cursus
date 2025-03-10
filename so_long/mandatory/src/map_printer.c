/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/22 22:39:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	map_type(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == EXIT || type == EMPTY)
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
}

void	print_movements(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, "\r", 1);
	write(1, "\033[32;01mMOVES: \033[0m", 20);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	free(move);
	move = NULL;
}
