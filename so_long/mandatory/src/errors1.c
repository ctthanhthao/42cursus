/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:15:09 by thchau            #+#    #+#             */
/*   Updated: 2025/02/21 15:52:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_filename(void)
{
	write(2, "\033[1;31mERROR\n", 14);
	write(2, "Filename must be a BER extension file\n\033[0m", 43);
	exit(EXIT_FAILURE);
}

void	error_wall(t_map *map)
{
	write(2, "\033[1;31mERROR\n", 14);
	write(2, "The map must be surrounded by walls\n\033[0m", 41);
	ft_free_array(&map->array);
	ft_free_array(&map->copy);
	exit(EXIT_FAILURE);
}

void	error_openfile(char *filename)
{
	write(2, "\033[1;31mERROR\n", 14);
	write(2, filename, ft_strlen(filename));
	write(2, " failed to open\n\033[0m", 21);
	exit(EXIT_FAILURE);
}

void	error_shape(t_map *map, char *msg)
{
	write(2, "\033[1;31mERROR\n", 14);
	write(2, msg, ft_strlen(msg));
	write(2, "\033[0m", 5);
	ft_free_array(&map->array);
	ft_free_array(&map->copy);
	exit(EXIT_FAILURE);
}

void	error_map_elements(t_map *map)
{
	write(2, "\033[1;31mERROR\n", 14);
	write(2, "Some required elements are invalid\n\033[0m", 40);
	ft_free_array(&map->array);
	ft_free_array(&map->copy);
	exit(EXIT_FAILURE);
}
