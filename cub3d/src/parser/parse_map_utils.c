/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:07:19 by thchau            #+#    #+#             */
/*   Updated: 2026/04/16 20:05:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	set_plane(t_game *game, double px, double py)
{
	game->player.plane_x = px;
	game->player.plane_y = py;
}

static void	set_dir(t_game *game, double dx, double dy)
{
	game->player.dir_x = dx;
	game->player.dir_y = dy;
}

static void	set_player_info(t_game *game, char c, int x, int y)
{
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (c == 'N')
	{
		set_dir(game, 0, -1);
		set_plane(game, 0.66, 0);
	}
	if (c == 'S')
	{
		set_dir(game, 0, 1);
		set_plane(game, -0.66, 0);
	}
	if (c == 'E')
	{
		set_dir(game, 1, 0);
		set_plane(game, 0, 0.66);
	}
	if (c == 'W')
	{
		set_dir(game, -1, 0);
		set_plane(game, 0, -0.66);
	}
}

/**
 * @brief This function standardizes your map by ensuring every row has the 
 * same width. It pads shorter lines with spaces to match the map's maximum 
 * width, creating a uniform rectangular grid structure.
 */
void	normalize_map(t_game *game)
{
	int		y;
	int		x;
	char	*new_line;

	y = 0;
	while (y < game->map.height)
	{
		new_line = malloc(game->map.width + 1);
		x = 0;
		while (x < game->map.width)
		{
			if (x < (int)ft_strlen(game->map.grid[y]))
				new_line[x] = game->map.grid[y][x];
			else
				new_line[x] = ' ';
			x++;
		}
		new_line[x] = '\0';
		free(game->map.grid[y]);
		game->map.grid[y] = ft_strdup(new_line);
		free(new_line);
		y++;
	}
}

/**
 * @brief This function searches through the game map to locate the player's 
 * starting position. It takes a t_game structure (which contains the game 
 * state, including the map) and returns information about where the player 
 * is positioned.
 */
int	find_player(t_game *game)
{
	int		x;
	int		y;
	int		found;
	char	c;

	y = -1;
	found = 0;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			c = game->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				set_player_info(game, c, x, y);
				found++;
			}
		}
	}
	if (found != 1)
		return (log_err("Map must have exactly one player(N/S/E/W)."), FAILURE);
	return (SUCCESS);
}
