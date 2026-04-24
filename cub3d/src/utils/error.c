/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:08:41 by phofer            #+#    #+#             */
/*   Updated: 2026/04/22 07:11:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Prints "Error\n<msg>\n" to stderr then exits via close_game.
void	fatal_error(t_game *game, const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	close_game(game);
}

// Destroys both mlx images and all four wall textures
// before destroying the window and display.
static void	destroy_mlx_images(t_game *game)
{
	int	i;

	if (game->img.img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->minimap.img_ptr && game->mlx)
		mlx_destroy_image(game->mlx, game->minimap.img_ptr);
	i = 0;
	while (i < TEX_COUNT)
	{
		if (game->textures[i].img_ptr && game->mlx)
			mlx_destroy_image(game->mlx, game->textures[i].img_ptr);
		i++;
	}
}

/*
** Releases all resources in safe order: images first, then window,
** then the display connection (Linux only), then the mlx handle.
** The map grid is freed last. Always exits with EXIT_SUCCESS so
** that the shell does not report a crash on normal quit.
*/
int	close_game(t_game *game)
{
	cleanup(game);
	destroy_mlx_images(game);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
}
