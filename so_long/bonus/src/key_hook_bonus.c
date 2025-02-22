/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/22 23:14:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	locate_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == PLAYER)
			{
				map->player.y = y;
				map->player.x = x;
			}
			x++;
		}
		y++;
	}
}

static void	print_counter(t_map *map)
{
	int		x;
	char	*num;
	char	*str_display;

	x = 0;
	while (x < map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, (map->y + 1) * IMG_PXL);
		x++;
	}
	num = ft_itoa(map->moves);
	str_display = ft_strjoin("MOVES: ", num);
	mlx_string_put(map->mlx, map->wnd, (map->x / 2) * IMG_PXL / 5,
		map->y * IMG_PXL + IMG_PXL / 2, 0x00000, str_display);
	free(num);
	num = NULL;
	free(str_display);
	str_display = NULL;
}

int	key_hook(int keycode, t_map *map)
{
	locate_player(map);
	if (keycode == ESC)
		ft_close(map);
	if (map->exit == 1)
		return (0);
	else if (keycode == A)
		player_move(map, 'x', LEFT);
	else if (keycode == S)
		player_move(map, 'y', DOWN);
	else if (keycode == D)
		player_move(map, 'x', RIGHT);
	else if (keycode == W)
		player_move(map, 'y', UP);
	print_counter(map);
	return (0);
}
