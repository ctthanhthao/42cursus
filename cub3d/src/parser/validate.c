/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:24:49 by thchau            #+#    #+#             */
/*   Updated: 2026/04/16 20:20:01 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < game->map.height)
	{
		copy[y] = ft_strdup(game->map.grid[y]);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

static int	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (1);
	if (ft_isspace(map[y][x]))
		return (1);
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'X')
		return (0);
	map[y][x] = 'X';
	if (flood_fill(map, x + 1, y, game) || flood_fill(map, x - 1, y, game)
		|| flood_fill(map, x, y + 1, game) || flood_fill(map, x, y - 1, game))
		return (1);
	return (0);
}

/**
 * @brief This function verifies that game map is properly enclosed and 
 * has no unreachable areas. It uses a flood-fill algorithm to ensure the 
 * player spawn location is surrounded by walls, preventing the player from 
 * escaping the playable area.
 */
int	validate_map(t_game *game)
{
	char	**copy;
	int		result;

	copy = copy_map(game);
	if (!copy)
		return (FAILURE);
	result = flood_fill(copy, game->player.x, game->player.y, game);
	free_arr(copy);
	if (result)
	{
		log_err("Map is not closed.");
		return (FAILURE);
	}
	printf("✅ VALID MAP\n");
	return (SUCCESS);
}

int	validate_elements(t_game *game)
{
	if (!game->texture_path[NORTH] || !game->texture_path[SOUTH]
		|| !game->texture_path[WEST] || !game->texture_path[EAST])
	{
		log_err("Missing required textures.");
		return (FAILURE);
	}
	if (game->floor_color == -1 || game->ceiling_color == -1)
	{
		log_err("Missing floor or ceiling colors.");
		return (FAILURE);
	}
	return (SUCCESS);
}
