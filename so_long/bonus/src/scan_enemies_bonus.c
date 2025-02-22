/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/22 23:19:47 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	count_enemies(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->array[y][x] == ENEMY)
				m++;
			x++;
		}
		x = 0;
		y++;
	}
	return (m);
}

static void	locate_enemies(t_map *map)
{
	int	y;
	int	x;
	int	m;

	m = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x && m < map->enemy.nbr)
		{
			if (map->array[y][x] == ENEMY)
			{
				map->enemy.array[0][m] = y;
				map->enemy.array[1][m] = x;
				m++;
			}
			x++;
		}
		y++;
	}
}

void	scan_enemies(t_map *map)
{
	map->enemy.nbr = count_enemies(map);
	if (map->enemy.nbr <= 0)
		return ;
	map->enemy.array = malloc(sizeof(int **) * 3);
	map->enemy.array[0] = malloc(sizeof(int *) * (map->enemy.nbr + 1));
	map->enemy.array[1] = malloc(sizeof(int *) * (map->enemy.nbr + 1));
	map->enemy.array[2] = 0;
	map->enemy.array[0][map->enemy.nbr] = 0;
	map->enemy.array[1][map->enemy.nbr] = 0;
	locate_enemies(map);
}
