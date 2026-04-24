/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:00:00 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Called every time the mouse moves. Computes the horizontal offset
** from the window centre, converts it to a rotation angle scaled by
** MOUSE_SENSITIVITY, then rotates the player's dir and plane vectors.
** The pointer is warped back to centre after each event so the offset
** never accumulates and the player can look indefinitely left or right.
** Vertical mouse movement is intentionally ignored (no pitch in cub3D).
*/
int	mouse_move(int x, int y, t_game *game)
{
	int	center_x;

	(void)y;
	if (!game->mouse_enabled)
		return (0);
	center_x = WIDTH / 2;
	if (!game->mouse_centered)
	{
		game->mouse_centered = 1;
		mlx_mouse_move(game->mlx, game->win, center_x, HEIGHT / 2);
		return (0);
	}
	game->mouse_delta_x = x - center_x;
	mlx_mouse_move(game->mlx, game->win, center_x, HEIGHT / 2);
	return (0);
}
