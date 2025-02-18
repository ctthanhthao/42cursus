/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/18 09:29:02 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	file_to_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"resources/wall_or.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"resources/wall_br.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"resources/exit.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"resources/collectible.xpm", &a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
			"resources/enemy.xpm", &a, &a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right = mlx_xpm_file_to_image(map->mlx,
			"resources/right.xpm", &a, &a);
	map->img.player_up = mlx_xpm_file_to_image(map->mlx,
			"resources/up.xpm", &a, &a);
	map->img.player_down = mlx_xpm_file_to_image(map->mlx,
			"resources/down.xpm", &a, &a);
	map->img.player_left = mlx_xpm_file_to_image(map->mlx,
			"resources/left.xpm", &a, &a);
}
