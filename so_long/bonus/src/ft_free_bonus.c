/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/22 22:51:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <X11/Xlib.h>
#include "../inc/so_long_bonus.h"

void	ft_free_array(char ***ret)
{
	int		i;
	char	**array;

	if (!ret || !*ret)
		return ;
	array = *ret;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	*ret = NULL;
}

void	ft_free_int_array(int ***ret)
{
	int		i;
	int		**array;

	if (!ret || !*ret)
		return ;
	array = *ret;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	*ret = NULL;
}

static void	free_player_images(t_map *map)
{
	if (map->img.player_left)
		mlx_destroy_image(map->mlx, map->img.player_left);
	if (map->img.player_keep_left)
		mlx_destroy_image(map->mlx, map->img.player_keep_left);
	if (map->img.player_right)
		mlx_destroy_image(map->mlx, map->img.player_right);
	if (map->img.player_keep_right)
		mlx_destroy_image(map->mlx, map->img.player_keep_right);
	if (map->img.player_up)
		mlx_destroy_image(map->mlx, map->img.player_up);
	if (map->img.player_keep_up)
		mlx_destroy_image(map->mlx, map->img.player_keep_up);
	if (map->img.player_down)
		mlx_destroy_image(map->mlx, map->img.player_down);
	if (map->img.player_keep_down)
		mlx_destroy_image(map->mlx, map->img.player_keep_down);
}

static void	free_images(t_map *map)
{
	if (!map->mlx)
		return ;
	if (map->img.empty)
		mlx_destroy_image(map->mlx, map->img.empty);
	if (map->img.collectible)
		mlx_destroy_image(map->mlx, map->img.collectible);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	if (map->img.exit)
		mlx_destroy_image(map->mlx, map->img.exit);
	if (map->img.enemy)
		mlx_destroy_image(map->mlx, map->img.enemy);
	if (map->img.enemy_flip)
		mlx_destroy_image(map->mlx, map->img.enemy_flip);
	free_player_images(map);
}

void	ft_clean_up(t_map *map)
{
	if (!map)
		return ;
	ft_free_array(&map->array);
	ft_free_array(&map->copy);
	ft_free_int_array(&map->enemy.array);
	free_images(map);
	if (map->wnd)
	{
		mlx_destroy_window(map->mlx, map->wnd);
		map->wnd = NULL;
	}
	if (map->mlx)
	{
        mlx_destroy_display(map->mlx);
		free(map->mlx);
		map->mlx = NULL;
	}
}
