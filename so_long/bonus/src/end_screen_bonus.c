/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/22 21:16:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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

static void	put_msg_in_center(t_map *map, char *msg, int color)
{
	int		text_width;
	int		x_center;
	int		y_center;

	text_width = 10 * ft_strlen(msg);
	x_center = (map->x * IMG_PXL / 2) - (text_width / 2);
	y_center = (map->y * IMG_PXL / 2);
	mlx_string_put(map->mlx, map->wnd, x_center, y_center, color, msg);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	mlx_clear_window(map->mlx, map->wnd);
	print_wall(map);
	put_msg_in_center(map, "~.~ CONGRATULATIONS ~.~", 0x800080);
	write(1, "\x1b[35;01m", 9);
	write(1, "GAME FINISHED\n", 15);
	write(1, "\x1b[0m", 5);
}

void	ft_lose(t_map *map)
{
	map->exit = 1;
	mlx_clear_window(map->mlx, map->wnd);
	print_wall(map);
	put_msg_in_center(map, "-- GAME OVER --", 0xF52200);
	write(1, "\x1b[35;01m", 9);
	write(1, "GAME OVER\n", 11);
	write(1, "\x1b[0m", 5);
}
