/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:56:00 by thchau            #+#    #+#             */
/*   Updated: 2025/02/23 10:05:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	error_path(t_map *map)
{
	write(2, "\033[1;31mError\n", 14);
	write(2, "No valid path\n\033[0m", 19);
	ft_free_array(&map->array);
	ft_free_array(&map->copy);
	ft_free_int_array(&map->enemy.array);
	exit(EXIT_FAILURE);
}

void	error_program(char *msg)
{
	write(2, "\033[1;31mError\n", 14);
	write(2, msg, ft_strlen(msg));
	write(2, "\033[0m", 5);
	exit(EXIT_FAILURE);
}
