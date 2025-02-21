/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:12:50 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 15:47:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	map_initializer(t_map *map, char **av)
{
	ft_memset(map, 0, sizeof(t_map));
	map->mlx = NULL;
	map->wnd = NULL;
	ft_memset(&map->img, 0, sizeof(map->img));
	map->array = NULL;
	map->copy = NULL;
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
	map->z = 0;
	map->action = 0;
	map->enemy.pos = 0;
	map->enemy.nbr = 0;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_program("Usage: ./so_long mapfile\n");
	map_initializer(&map, av);
	map_validator(&map);
	map.mlx = mlx_init();
	if (!map.mlx)
		error_program("MLX initialization failed\n");
	map.wnd = mlx_new_window(map.mlx, map.x * IMG_PXL,
			map.y * IMG_PXL + IMG_PXL * 1.25, WND_NAME);
	if (!map.wnd)
		error_program("Window creation failed\n");
	file_to_image(&map);
	map_printer(&map);
	scan_enemies(&map);
	if (map.enemy.nbr > 0)
		mlx_loop_hook(map.mlx, move_enemies, &map);
	mlx_hook(map.wnd, 17, 0, ft_close, &map);
	mlx_key_hook(map.wnd, key_hook, &map);
	mlx_loop(map.mlx);
}
