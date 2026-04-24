/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:00:22 by thchau            #+#    #+#             */
/*   Updated: 2026/04/23 16:23:49 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static bool	is_file_empty(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!ft_isspace(lines[i][j]) && lines[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
/**
 * @brief This function is the orchestrator of the entire configuration file 
 * parsing workflow. It reads a configuration file into memory, sequentially 
 * validates and extracts textures, colors, and map data, and returns success
 * only when all components are properly loaded and validated.
 */

int	parse_file(t_game *game, const char *filename)
{
	int		line_count;
	char	**lines;

	line_count = 0;
	lines = read_file_lines(filename, &line_count);
	if (!lines)
		return (FAILURE);
	if (is_file_empty(lines))
	{
		free_arr(lines);
		log_err("File is empty.");
		return (FAILURE);
	}
	if (parse_textures(game, lines, line_count) != SUCCESS)
		return (free_arr(lines), FAILURE);
	if (parse_colors(game, lines, line_count) != SUCCESS)
		return (free_arr(lines), FAILURE);
	if (validate_elements(game) != SUCCESS)
		return (free_arr(lines), FAILURE);
	if (parse_map(game, lines, line_count) != SUCCESS)
		return (free_arr(lines), FAILURE);
	if (validate_map(game) != SUCCESS)
		return (free_arr(lines), FAILURE);
	free_arr(lines);
	return (SUCCESS);
}
