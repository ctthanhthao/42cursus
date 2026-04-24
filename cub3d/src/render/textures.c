/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:50:29 by thchau            #+#    #+#             */
/*   Updated: 2026/04/01 21:13:38 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(void *mlx, t_img *img, char *path)
{
	char	*msg;

	if (!path)
	{
		log_err("Texture path is NULL.");
		return (FAILURE);
	}
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
	{
		msg = ft_strjoin("Failed to load texture: ", path);
		if (!msg)
			log_err("Failed to load texture.");
		else
		{
			log_err(msg);
			free(msg);
		}
		return (FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
		return (log_err("Failed to get texture data address."), FAILURE);
	return (SUCCESS);
}

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < TEX_COUNT)
	{
		if (load_texture(game->mlx, &game->textures[i],
				game->texture_path[i]) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
