/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:15:40 by phofer            #+#    #+#             */
/*   Updated: 2026/04/22 14:13:47 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Wall Face -> Texture Selector
** Purpose: Determines which of the 4 wall textures (N/S/E/W) to use for
**          the current ray hit.
** Logic:   Checks ray->side to know if a vertical or horizontal wall was hit,
**          then checks step_x/y direction to identify the exact face.
**          Returns a texture index constant (TEX_NO, TEX_SO, TEX_EA, TEX_WE).
*/
static int	get_tex_index(t_ray *ray)
{
	if (ray->side == 0 && ray->step_x > 0)
		return (TEX_EA);
	if (ray->side == 0 && ray->step_x < 0)
		return (TEX_WE);
	if (ray->side == 1 && ray->step_y > 0)
		return (TEX_SO);
	return (TEX_NO);
}

/*
** Texture Pixel Sampler
** Purpose: Fetches a single pixel color from a texture at (tex_x, tex_y).
** Logic:   Computes the byte offset directly into the raw image buffer
**          (tex->addr) using line length and bit depth. If the hit wall was
**          a horizontal side (side == 1), darkens the color via COLOR_DARK()
**          to simulate a shadow effect and give the scene a basic sense of
**          lighting.
*/
static int	get_tex_color(t_img *tex, int tex_x, int tex_y, int side)
{
	char	*src;
	int		color;

	src = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	color = *(unsigned int *)src;
	if (side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}

/*
** Horizontal Texture Coordinate Calculator
** Purpose: Figures out the exact horizontal pixel column to sample from the
**          texture — where on the wall did the ray land?
** Logic:   Uses perp_wall_dist and the player's position to compute wall_x,
**          the fractional hit offset within the cell (0.0–1.0), then scales
**          it to texture width. Mirrors the result in cases where the texture
**          would otherwise appear flipped (e.g. ray approaching from the
**          opposite direction).
*/
static int	get_tex_x(t_game *game, t_ray *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->step_x > 0)
		|| (ray->side == 1 && ray->step_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

/*
** Textured Wall Slice Renderer
** Purpose: Renders one full vertical stripe of wall pixels onto the screen
**          for column x.
** Logic:   Selects the correct texture and horizontal sample column, then
**          calculates tex_step (how many texture pixels to advance per screen
**          pixel) to handle wall height scaling. Walks draw_start->draw_end,
**          sampling the texture at each step and writing the pixel to the
**          frame buffer. The (int)tex_pos & (tex->height - 1) bitmask keeps
**          the Y sample safely within texture bounds.
*/
static void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_img	*tex;
	int		tex_x;
	double	tex_step;
	double	tex_pos;

	tex = &game->textures[get_tex_index(ray)];
	tex_x = get_tex_x(game, ray, tex);
	tex_step = (double)tex->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2)
		* tex_step;
	while (ray->draw_start <= ray->draw_end)
	{
		put_pixel(&game->img, x, ray->draw_start,
			get_tex_color(tex, tex_x, (int)tex_pos & (tex->height - 1),
				ray->side));
		tex_pos += tex_step;
		ray->draw_start++;
	}
}

/*
* Main Frame Renderer (entry point): produces one complete frame and pushes it
* to the window.
*/
int	render(t_game *game)
{
	t_ray	ray;
	int		x;

	handle_movement(game);
	draw_background(game);
	x = 0;
	while (x < WIDTH)
	{
		cast_ray(game, &ray, x);
		draw_column(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	return (0);
}
