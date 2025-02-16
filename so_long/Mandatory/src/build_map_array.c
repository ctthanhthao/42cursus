/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/16 16:11:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	exit_with_fail(t_map *map)
{
	ft_clean_up(map);
	exit(EXIT_FAILURE);
}

void	build_map_array(t_map *map)
{
	int		fd;
	char	*line;
	
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_openfile(map->filename);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->file = sl_strjoin(map->file, line);
		free(line);
		line = NULL;
		if (!map->file)
			exit_with_fail(map);
		map->y++;
	}
	close(fd);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	free(map->file);
	map->file = NULL;
	if (!map->array || !map->copy)
		exit_with_fail(map);
}
