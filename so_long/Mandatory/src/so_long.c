/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/11 07:31:20 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_initializer(t_map *map, char **av)
{
	map->filename = av[1];
	map->moves = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->y = 0;
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
		printf("map_init DONE\n");
		map_checker(&map);
		printf("map_checker DONE\n");
		map.mlx = mlx_init();
		printf("mlx_init DONE with map.mlx %p\n", map.mlx);
		map.wnd = mlx_new_window(map.mlx, map.x
				* IMG_PXL, map.y * IMG_PXL, WND_NAME);
		printf("mlx_new_window DONE\n");
		file_to_image(&map);
		printf("file_to_image DONE\n");
		map_printer(&map);
		printf("map_printer DONE\n");
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		printf("mlx_hook DONE\n");
		mlx_key_hook(map.wnd, key_hook, &map);
		printf("mlx_key_hook DONE\n");
		mlx_loop(map.mlx);
		printf("mlx_loop DONE\n");
	}
	write(2, "\033[1;31m🛑ERROR:", 18);
	write(2, "Usage: ./so_long mapfile\n\033[0m", 30);
	exit(EXIT_FAILURE);
}
