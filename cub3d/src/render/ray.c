/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:14:06 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 14:08:20 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Ray Initializer
** Purpose: Sets up the ray's direction and grid position for screen column x.
** Logic:   Converts x to a camera-space value (camera_x) in range [-1, 1],
**          then combines the player's direction vector with the camera plane
**          to produce the ray direction. Snaps the starting map cell to the
**          player's integer grid position. Precomputes delta_dist_x/y — the
**          distance the ray must travel to cross one full grid unit on each
**          axis. Uses 1e30 as infinity when a direction component is zero to
**          avoid division by zero.
*/
static void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / WIDTH - 1.0;
	ray->ray_dir_x = game->player.dir_x
		+ game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y
		+ game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->ray_dir_x == 0.0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0.0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
}

/*
** Step Direction & Initial Side Distance Calculator
** Purpose: Determines which direction the ray steps through the grid (+1/-1)
**          and how far it is to the very first grid boundary on each axis.
** Logic:   For each axis, checks the sign of the ray direction to set step_x/y.
**          Then calculates the initial side_dist — the partial distance from
**          the player's current position to the nearest grid line — by measuring
**          the fractional offset within the current cell and scaling by 
**          delta_dist.
**          This ensures the DDA loop starts correctly regardless of which
**          sub-cell the player is standing in.
*/
static void	calc_step_side(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player.y)
			* ray->delta_dist_y;
	}
}

/*
** DDA Grid Traversal Loop
** Purpose: Walks the ray through the map grid cell by cell until it hits a
**          wall or goes out of bounds.
** Logic:   Calls dda_step() each iteration to advance to the next grid
**          boundary (see dda_step brief). Before each step, checks if the
**          current cell is out of map bounds (safety exit) or contains a
**          wall tile ('1'). Sets ray->hit = 1 and breaks on either condition.
*/
static void	perform_dda(t_game *game, t_ray *ray)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->map_x < 0 || ray->map_y < 0
			|| ray->map_x >= game->map.width
			|| ray->map_y >= game->map.height)
		{
			ray->hit = 1;
			break ;
		}
		if (game->map.grid[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
			break ;
		}
		dda_step(ray);
	}
}

/*
** Wall Slice Height Calculator
** Purpose: Computes how tall the wall slice should appear on screen and which
**          pixel rows to draw it between.
** Logic:   Derives perp_wall_dist — the perpendicular (non-fisheye) distance
**          from the player to the wall — by subtracting one delta from the
**          accumulated side_dist. Divides screen HEIGHT by this distance to
**          get line_height (taller = closer). Clamps draw_start and draw_end
**          to screen bounds so out-of-range walls don't cause buffer overflows.
*/
static void	calc_wall_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = HEIGHT / 2 - ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = HEIGHT / 2 + ray->line_height / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

/*
** Full Ray Pipeline (entry point)
** Purpose: Executes the complete ray casting pipeline for screen column x,
**          populating the ray struct ready for rendering.
*/
void	cast_ray(t_game *game, t_ray *ray, int x)
{
	init_ray(game, ray, x);
	calc_step_side(game, ray);
	perform_dda(game, ray);
	calc_wall_height(ray);
}
