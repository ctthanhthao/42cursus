/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/16 19:27:49 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close(t_map *map)
{
	ft_clean_up(map);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	mlx_string_put(map->mlx, map->wnd,
		map->x / 2 * IMG_PXL - 50, map->y / 2 * IMG_PXL, 0x800080,
		"~.~ CONGRATULATIONS ~.~");
	write(1, "\n", 1);
	write(1, "\x1b[35;01m", 9);
	write(1, "GAME FINISHED\n", 15);
	write(1, "\x1b[0m", 5); 
}
