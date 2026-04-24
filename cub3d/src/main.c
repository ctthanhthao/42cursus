/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:22:49 by phofer            #+#    #+#             */
/*   Updated: 2026/04/16 19:19:49 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_extension(const char *filename, const char *ext)
{
	int	flen;
	int	elen;

	if (!filename || !ext)
		return (0);
	flen = ft_strlen(filename);
	elen = ft_strlen(ext);
	if (flen <= elen)
		return (0);
	return (ft_strncmp(filename + flen - elen, ext, elen) == 0);
}

// Entry point: validates argument count then launches the game.
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		log_err("Usage: ./cub3D <map.cub>");
		return (1);
	}
	if (!ft_check_extension(argv[1], ".cub"))
	{
		log_err("File must have .cub extension");
		return (1);
	}
	start_game(&game, argv[1]);
	return (0);
}
