/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/16 17:35:39 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	validate_file(t_map *map)
{
	char	*file_ex;

	file_ex = ft_strchr(map->filename, '.');
	if (!file_ex || !ft_strnstr(file_ex, ".ber", 4))
		error_filename();
}

static void	validate_elements(t_map *map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == '0' && map->array[y][x] == '1')
				error_map_elements(map);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		error_map_elements(map);
}

static void	validate_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x)
	{
		if (map->array[0][x] != '1')
			error_wall(map);
		x++;
	}
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != '1' ||
				map->array[y][map->x - 1] != '1')
			error_wall(map);
		y++;
	}
	x = 0;
	while (x < map->x)
	{
		if (map->array[y - 1][x] != '1')
			error_wall(map);
		x++;
	}
}

void	validate_shape(t_map *map)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	if (map->y < 2)
		error_shape(map);
	max = ft_strlen(map->array[y]);
	while (y < map->y)
	{
		x = ft_strlen(map->array[y]);
		if (max != x)
			error_shape(map);
		y++;
	}
	map->x = max;
}

void	map_validator(t_map *map)
{
	validate_file(map);
	build_map_array(map);
	validate_shape(map);
	validate_elements(map);
	validate_wall(map);
	validate_path(map);
	ft_free_array(&map->copy);
}
