/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/16 19:06:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_initializer(t_map *map, char **av)
{
	ft_memset(map, 0, sizeof(t_map));
	map->mlx = NULL;
	map->wnd = NULL;
	ft_memset(&map->img, 0, sizeof(map->img));
	map->file = NULL;
	map->array = NULL;
	map->copy = NULL;
	map->fd = -1;
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
	map->c_check = 0;
	map->e_check = 0;
	map->player.y = 0;
	map->player.x = 0;
	map->exit = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		map_initializer(&map, av);
		map_validator(&map);
		map.mlx = mlx_init();
		map.wnd = mlx_new_window(map.mlx, map.x
				* IMG_PXL, map.y * IMG_PXL, WND_NAME);
		printf("MLX: %p, Window: %p\n", map.mlx, map.wnd);
		file_to_image(&map);
		map_printer(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
	else
	{
		write(2, "\033[1;31mERROR:", 14);
		write(2, "Usage: ./so_long mapfile\n\033[0m", 30);
		exit(EXIT_FAILURE);
	}
}
