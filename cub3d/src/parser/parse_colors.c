/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:15:58 by thchau            #+#    #+#             */
/*   Updated: 2026/04/16 20:04:06 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	set_ceiling_color(t_game *game, char *val)
{
	if (game->ceiling_color == -1)
		return (set_rgb_line(&game->ceiling_color, val));
	else
		return (log_err("Duplicate ceiling color."), FAILURE);
}

static int	set_floor_color(t_game *game, char *val)
{
	if (game->floor_color == -1)
		return (set_rgb_line(&game->floor_color, val));
	else
		return (log_err("Duplicate floor color."), FAILURE);
}

/**
 * @brief The function reads through configuration file lines, identifies color
 * declarations (marked by 'C' for ceiling and 'F' for floor), validates and 
 * stores them in the game structure, and stops parsing when it reaches actual 
 * map content.
 */
int	parse_colors(t_game *game, char **lines, int line_count)
{
	int		i;
	char	*line;

	i = 0;
	while (i < line_count)
	{
		line = lines[i];
		while (ft_isspace(*line))
			line++;
		if (line[0] == 'C' && ft_isspace(line[1]))
		{
			if (set_ceiling_color(game, line) == FAILURE)
				return (FAILURE);
		}
		else if (line[0] == 'F' && ft_isspace(line[1]))
		{
			if (set_floor_color(game, line) == FAILURE)
				return (FAILURE);
		}
		else if (is_map_line(line))
			break ;
		i++;
	}
	return (SUCCESS);
}
