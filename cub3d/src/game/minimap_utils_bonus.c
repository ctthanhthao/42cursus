/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:00:00 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

int	get_tile_color(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0
		|| map_x >= game->map.width || map_y >= game->map.height)
		return (MM_VOID);
	if (game->map.grid[map_y][map_x] == '1')
		return (MM_WALL);
	return (MM_FLOOR);
}

void	put_pixel_alpha(t_img *img, int x, int y, t_blend blend)
{
	char	*dst;
	int		bg;
	int		r;
	int		g;
	int		b;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	bg = *(unsigned int *)dst;
	r = (((blend.color >> 16) & 0xFF) * blend.alpha
			+ ((bg >> 16) & 0xFF) * (255 - blend.alpha)) / 255;
	g = (((blend.color >> 8) & 0xFF) * blend.alpha
			+ ((bg >> 8) & 0xFF) * (255 - blend.alpha)) / 255;
	b = ((blend.color & 0xFF) * blend.alpha
			+ (bg & 0xFF) * (255 - blend.alpha)) / 255;
	*(unsigned int *)dst = (r << 16) | (g << 8) | b;
}

void	draw_tile(t_game *game, int px, int py, int color)
{
	int	dx;
	int	dy;

	dy = 0;
	while (dy < TILE)
	{
		dx = 0;
		while (dx < TILE)
			put_pixel(&game->minimap, px + dx++, py + dy, color);
		dy++;
	}
}

void	draw_fov_spoke(t_game *game, double rx, double ry)
{
	int		cx;
	int		cy;
	int		i;
	t_blend	blend;

	cx = MINIMAP_SIZE / 2;
	cy = MINIMAP_SIZE / 2;
	blend.color = MM_FOV;
	i = 0;
	while (i < RAY_LEN)
	{
		blend.alpha = 200 - (200 * i / RAY_LEN);
		put_pixel_alpha(&game->minimap,
			cx + (int)(rx * i), cy + (int)(ry * i), blend);
		i++;
	}
}

void	composite_minimap(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			color = *(unsigned int *)(game->minimap.addr
					+ (y * game->minimap.line_len
						+ x * (game->minimap.bpp / 8)));
			put_pixel(&game->img, 10 + x,
				HEIGHT - MINIMAP_SIZE - 10 + y, color);
			x++;
		}
		y++;
	}
}
