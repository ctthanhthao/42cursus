/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_border_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:47:07 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minimap_bonus.h"

static void	draw_h_border(t_game *game, int ox, int oy, int t)
{
	int	i;

	i = -t;
	while (i < MINIMAP_SIZE + t)
	{
		put_pixel(&game->img, ox + i, oy - t - 1, MM_BORDER_C);
		put_pixel(&game->img, ox + i, oy + MINIMAP_SIZE + t, MM_BORDER_C);
		i++;
	}
}

static void	draw_v_border(t_game *game, int ox, int oy, int t)
{
	int	i;

	i = -t;
	while (i < MINIMAP_SIZE + t)
	{
		put_pixel(&game->img, ox - t - 1, oy + i, MM_BORDER_C);
		put_pixel(&game->img, ox + MINIMAP_SIZE + t, oy + i, MM_BORDER_C);
		i++;
	}
}

void	draw_minimap_border(t_game *game)
{
	int	ox;
	int	oy;
	int	t;

	ox = 10;
	oy = HEIGHT - MINIMAP_SIZE - 10;
	t = 0;
	while (t < MM_BORDER_W)
	{
		draw_h_border(game, ox, oy, t);
		draw_v_border(game, ox, oy, t);
		t++;
	}
}
