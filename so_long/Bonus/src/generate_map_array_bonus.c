/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/11 07:28:36 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	map_array(t_map *map)
{
	int		fd;
	char	*line;
	char	*file;

	map->y = 0;
	line = "";
	file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		error_openfile();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		file = ft_strjoinfree(file, line);
		if (file == NULL)
			free(file);
		free(line);
		map->y++;
	}
	close(fd);
	map->array = ft_split(file, '\n');
	map->copy = ft_split(file, '\n');
	free(file);
}
