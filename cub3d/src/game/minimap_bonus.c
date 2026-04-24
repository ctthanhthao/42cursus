/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:42:29 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

static void	clear_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
			put_pixel(&game->minimap, x++, y, MM_BORDER);
		y++;
	}
}

static void	draw_minimap_grid(t_game *game)
{
	int		map_x;
	int		map_y;
	int		off_x;
	int		off_y;

	off_x = (int)game->player.x - (MINIMAP_SIZE / 2 / TILE);
	off_y = (int)game->player.y - (MINIMAP_SIZE / 2 / TILE);
	map_y = off_y;
	while (map_y < off_y + MINIMAP_SIZE / TILE)
	{
		map_x = off_x;
		while (map_x < off_x + MINIMAP_SIZE / TILE)
		{
			draw_tile(game, (map_x - off_x) * TILE, (map_y - off_y) * TILE,
				get_tile_color(game, map_x, map_y));
			map_x++;
		}
		map_y++;
	}
}

static void	draw_minimap_player(t_game *game)
{
	int	cx;
	int	cy;
	int	dx;
	int	dy;

	cx = MINIMAP_SIZE / 2;
	cy = MINIMAP_SIZE / 2;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
			put_pixel(&game->minimap, cx + dx++, cy + dy, MM_PLAYER);
		dy++;
	}
}

static void	draw_minimap_ray(t_game *game)
{
	int		s;
	double	t;
	double	rx;
	double	ry;
	double	len;

	s = 0;
	while (s <= FOV_STEPS)
	{
		t = -1.0 + 2.0 * s / FOV_STEPS;
		rx = game->player.dir_x + game->player.plane_x * t;
		ry = game->player.dir_y + game->player.plane_y * t;
		len = sqrt(rx * rx + ry * ry);
		draw_fov_spoke(game, rx / len, ry / len);
		s++;
	}
}

void	render_minimap(t_game *game)
{
	clear_minimap(game);
	draw_minimap_grid(game);
	draw_minimap_ray(game);
	draw_minimap_player(game);
	composite_minimap(game);
	draw_minimap_border(game);
}
