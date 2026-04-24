/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:39:57 by phofer            #+#    #+#             */
/*   Updated: 2026/04/14 19:55:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_game(t_game *game, char *map_path)
{
	int	i;

	if (parse_file(game, map_path) == FAILURE)
	{
		cleanup(game);
		exit(EXIT_FAILURE);
	}
	printf("floor color: %i\n", game->floor_color);
	printf("ceiling color: %i\n", game->ceiling_color);
	printf("NO: %s\n", game->texture_path[NORTH]);
	printf("SO: %s\n", game->texture_path[SOUTH]);
	printf("EA: %s\n", game->texture_path[EAST]);
	printf("WE: %s\n", game->texture_path[WEST]);
	i = 0;
	while (i < game->map.height)
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
	if (load_textures(game) == FAILURE)
	{
		cleanup(game);
		exit(EXIT_FAILURE);
	}
}

void	start_game(t_game *game, char *map)
{
	initialize(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		fatal_error(game, "mlx_init failed");
	init_game(game, map);
	init_mlx(game);
	mlx_loop(game->mlx);
	cleanup(game);
}
