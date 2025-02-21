/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/20 21:24:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	exit_with_fail(t_map *map)
{
	ft_clean_up(map);
	exit(EXIT_FAILURE);
}

static char	*build_file(t_map *map)
{
	int		fd;
	char	*line;
	char	*file;
	
	line = "";
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_openfile(map->filename);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		file = sl_strjoin(file, line);
		free(line);
		line = NULL;
		if (!file)
			exit_with_fail(map);
		map->y++;
	}
	close(fd);
	return (file);
}

void	build_map_array(t_map *map)
{
	char	*file;
	
	file = build_file(map);
	map->array = ft_split(file, '\n');
	map->copy = ft_split(file, '\n');
	free(file);
	file = NULL;
	if (!map->array || !map->copy)
		exit_with_fail(map);
}

