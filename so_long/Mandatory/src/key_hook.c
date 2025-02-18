/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/18 09:41:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	locate_player(t_map *map)
{
	map->player.y = 0;
	map->player.x = 0;
	while (map->player.y < map->y)
	{
		while (map->player.x < map->x)
		{
			if (map->array[map->player.y][map->player.x] == PLAYER)
				break ;
			map->player.x++;
		}
		if (map->array[map->player.y][map->player.x] == PLAYER)
			break ;
		map->player.x = 0;
		map->player.y++;
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
		move(map, 'x', LEFT);
	else if (keycode == S)
		move(map, 'y', DOWN);
	else if (keycode == D)
		move(map, 'x', RIGHT);
	else if (keycode == W)
		move(map, 'y', UP);
	return (0);
}
