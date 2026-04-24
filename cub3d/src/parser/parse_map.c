/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:04:24 by thchau            #+#    #+#             */
/*   Updated: 2026/04/16 20:08:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

bool	is_map_line(char *line)
{
	int	i;
	int	len;

	if (!line || !line[0])
		return (false);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\r')
		line[len - 1] = '\0';
	i = 0;
	while (line[i])
	{
		if (!is_map_char(line[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief This function searches through an array of lines to locate the first
 * line that represents the beginning of a map structure. It returns the index
 * of that line, or -1 if no valid map start is found.
 */
static int	find_map_start(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (is_map_line(lines[i]) && lines[i][0] != '\0')
		{
			if (lines[i][0] == '1' || lines[i][0] == ' '
				|| lines[i][0] == '\t')
				return (i);
		}
		i++;
	}
	return (-1);
}

static int	get_max_width(char **map, int height)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < height)
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static int	build_map(t_game *game, char **lines, int start, int height)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		game->map.grid[i] = NULL;
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (!is_map_line(lines[start + i]))
			return (log_err("Map must be the last one."), FAILURE);
		game->map.grid[i] = ft_strdup(lines[start + i]);
		if (!game->map.grid[i])
		{
			game->map.grid[i] = NULL;
			free_arr(game->map.grid);
			return (FAILURE);
		}
		i++;
	}
	game->map.grid[i] = NULL;
	return (SUCCESS);
}

/**
 * @brief Parses the map data from input lines
 * 		  Processes the input lines to extract and validate map configuration.
 *        Populates the game structure with parsed map information.
 *
 * Return: 1 on success, -1 on failure
 */
int	parse_map(t_game *game, char **lines, int count)
{
	int	start;
	int	height;

	start = find_map_start(lines, count);
	if (start == -1)
		return (log_err("There is no map in the file."), FAILURE);
	height = count - start;
	game->map.grid = malloc(sizeof(char *) * (height + 1));
	if (!game->map.grid)
		return (log_err("allocate map.grid failed."), FAILURE);
	if (build_map(game, lines, start, height) == FAILURE)
		return (FAILURE);
	game->map.height = height;
	game->map.width = get_max_width(game->map.grid, height);
	normalize_map(game);
	return (find_player(game));
}
