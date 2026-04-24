/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:00:00 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
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

static void	init_minimap_image(t_game *game)
{
	game->minimap.img_ptr = mlx_new_image(game->mlx,
			MINIMAP_SIZE, MINIMAP_SIZE);
	if (!game->minimap.img_ptr)
		fatal_error(game, "minimap mlx_new_image failed");
	game->minimap.addr = mlx_get_data_addr(
			game->minimap.img_ptr,
			&game->minimap.bpp,
			&game->minimap.line_len,
			&game->minimap.endian);
	if (!game->minimap.addr)
		fatal_error(game, "minimap mlx_get_data_addr failed");
	game->minimap.width = MINIMAP_SIZE;
	game->minimap.height = MINIMAP_SIZE;
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_KEYPRESS, MASK_KEYPRESS, key_hook, game);
	mlx_hook(game->win, EVENT_KEYRELEASE, MASK_KEYRELEASE, key_release, game);
	mlx_hook(game->win, EVENT_DESTROY, 0, close_game, game);
	mlx_hook(game->win, EVENT_MOUSEMOVE, MASK_MOUSEMOVE, mouse_move, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game->mlx, render, game);
}

void	init_mlx(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		fatal_error(game, "mlx_new_window failed");
	init_image(game);
	init_minimap_image(game);
	setup_hooks(game);
}
