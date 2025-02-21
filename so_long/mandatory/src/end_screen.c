/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 16:53:22 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close(t_map *map)
{
	ft_clean_up(map);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	print_wall(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
				x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
	while (x <= map->x)
	{
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL);
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall,
			x * IMG_PXL, map->y * IMG_PXL + IMG_PXL);
		x++;
	}
}

void	ft_win(t_map *map)
{
	char	*msg;
	int		text_width;
	int		x_center;
	int		y_center;
	
	map->exit = 1;
	mlx_clear_window(map->mlx, map->wnd);
	print_wall(map);
	msg = "~.~ CONGRATULATIONS ~.~";
	text_width = 10 * ft_strlen(msg);
	x_center = (map->x * IMG_PXL / 2) - (text_width / 2);
	y_center = (map->y * IMG_PXL / 2);
	mlx_string_put(map->mlx, map->wnd, x_center, y_center, 0x800080, msg);
	write(1, "\n", 1);
	write(1, "\x1b[35;01m", 9);
	write(1, "GAME FINISHED\n", 15);
	write(1, "\x1b[0m", 5);
}
