/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:52:10 by phofer            #+#    #+#             */
/*   Updated: 2026/04/22 08:09:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_image(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img_ptr)
		fatal_error(game, "mlx_new_image failed");
	game->img.addr = mlx_get_data_addr(
			game->img.img_ptr,
			&game->img.bpp,
			&game->img.line_len,
			&game->img.endian);
	if (!game->img.addr)
		fatal_error(game, "mlx_get_data_addr failed");
	game->img.width = WIDTH;
	game->img.height = HEIGHT;
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_KEYPRESS, MASK_KEYPRESS, key_hook, game);
	mlx_hook(game->win, EVENT_KEYRELEASE, MASK_KEYRELEASE, key_release, game);
	mlx_hook(game->win, EVENT_DESTROY, 0, close_game, game);
	mlx_loop_hook(game->mlx, render, game);
}

void	init_mlx(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		fatal_error(game, "mlx_new_window failed");
	init_image(game);
	setup_hooks(game);
}
