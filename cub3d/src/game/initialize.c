/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:35:33 by thchau            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

static void	init_map(t_game *game)
{
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
}

static void	init_image(t_img *img)
{
	img->img_ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

static void	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		init_image(&game->textures[i]);
		game->texture_path[i] = NULL;
		i++;
	}
}

void	initialize(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->keys_held = 0;
	game->mouse_delta_x = 0;
	game->mouse_centered = 0;
	game->mouse_enabled = 0;
	init_image(&game->img);
	init_image(&game->minimap);
	init_player(&game->player);
	init_map(game);
	init_textures(game);
}
