/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:53:46 by phofer            #+#    #+#             */
/*   Updated: 2026/04/22 07:45:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "cub3d.h"

typedef struct s_blend
{
	int	color;
	int	alpha;
}	t_blend;

/* ── Tile & geometry ───────────────────────────────────────────────────── */
# define TILE        8
# define RAY_LEN     14
# define FOV_STEPS   40

/* ── Colors ────────────────────────────────────────────────────────────── */
# define MM_WALL     0x888888
# define MM_FLOOR    0x222222
# define MM_VOID     0x000000
# define MM_BORDER   0x444444
# define MM_PLAYER   0xFF4444
# define MM_FOV      0xFF6633
# define MM_BORDER_W 2
# define MM_BORDER_C 0xAAAAAA

/* ── minimap_bonus.c ───────────────────────────────────────────────────── */
void	render_minimap(t_game *game);

/* ── minimap_utils_bonus.c ─────────────────────────────────────────────── */
int		get_tile_color(t_game *game, int map_x, int map_y);
void	put_pixel_alpha(t_img *img, int x, int y, t_blend blend);
void	draw_tile(t_game *game, int px, int py, int color);
void	draw_fov_spoke(t_game *game, double rx, double ry);
void	composite_minimap(t_game *game);

/* ── minimap_border_bonus.c ────────────────────────────────────────────── */
void	draw_minimap_border(t_game *game);

#endif
