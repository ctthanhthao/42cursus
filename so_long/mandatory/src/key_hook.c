/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 14:50:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	key_hook(int keycode, t_map *map)
{
	locate_player(map);
	if (keycode == ESC)
		ft_close(map);
	else if (map->exit == 1)
		return (0);
	else if (keycode == A)
		player_move(map, 'x', LEFT);
	else if (keycode == S)
		player_move(map, 'y', DOWN);
	else if (keycode == D)
		player_move(map, 'x', RIGHT);
	else if (keycode == W)
		player_move(map, 'y', UP);
	print_movements(map);
	return (0);
}
