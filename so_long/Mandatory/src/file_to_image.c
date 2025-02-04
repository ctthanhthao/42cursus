/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:52:15 by jcheel-n          #+#    #+#             */
/*   Updated: 2025/02/03 22:16:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	file_to_image(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"Resources/wall_or.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"Resources/wall_br.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"Resources/exit.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"Resources/collectible.xpm", &a, &a);
	map->img.enemy = mlx_xpm_file_to_image(map->mlx,
			"Resources/enemy.xpm", &a, &a);
	file_to_image_player(map);
}

void	file_to_image_player(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right.xpm", &a, &a);
	map->img.player_right2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/right-2-40.xpm", &a, &a);
	map->img.player_up1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up.xpm", &a, &a);
	map->img.player_up2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/up-2-40.xpm", &a, &a);
	map->img.player_down1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down.xpm", &a, &a);
	map->img.player_down2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/down-2-40.xpm", &a, &a);
	map->img.player_left1 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left.xpm", &a, &a);
	map->img.player_left2 = mlx_xpm_file_to_image(map->mlx,
			"Resources/left-2-40.xpm", &a, &a);
}
