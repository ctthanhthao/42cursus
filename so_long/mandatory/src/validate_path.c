/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/20 19:52:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;

	type = map->copy[y][x];
	if (type == COLLECTIBLE)
		map->c_check -= 1;
	else if (type == EXIT)
		map->e_check -= 1;
	else if (type != EMPTY && type != PLAYER)
		return ;
	map->copy[y][x] = '1';
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

void	validate_path(t_map *map)
{
	int	x;
	int	y;
	
	map->c_check = map->c;
	map->e_check = map->e;
	locate_player(map);
	x = map->player.x;
	y = map->player.y;
	move_on_paths(x, y, map);
	if (map->c_check != 0 || map->e_check >= map->e)
		error_path(map);
}
