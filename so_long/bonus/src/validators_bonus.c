/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 08:57:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	validate_file(char *filename)
{
	char	*file_ex;

	file_ex = ft_strchr(filename, '.');
	if (!file_ex || !ft_strnstr(file_ex, ".ber", 4))
		error_filename();
}

static void	validate_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == COLLECTIBLE)
				map->c += 1;
			else if (map->array[y][x] == EXIT)
				map->e += 1;
			else if (map->array[y][x] == PLAYER)
				map->p += 1;
			else if (map->array[y][x] != EMPTY && map->array[y][x] != WALL &&
				map->array[y][x] != ENEMY)
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
		if (map->array[0][x] != WALL)
			error_wall(map);
		x++;
	}
	y = 1;
	while (y < map->y)
	{
		if (map->array[y][0] != WALL || map->array[y][map->x - 1] != WALL)
			error_wall(map);
		y++;
	}
	x = 0;
	while (x < map->x)
	{
		if (map->array[y - 1][x] != WALL)
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
	validate_file(map->filename);
	build_map_array(map);
	validate_shape(map);
	validate_elements(map);
	validate_wall(map);
	validate_path(map);
	ft_free_array(&map->copy);
}
