/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:00:00 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Rotates dir and plane vectors by angle using a 2D rotation matrix.
void	rotate_player(t_player *p, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

/*
** Moves the player by (dx, dy) with per-axis wall collision.
** Each axis is tested independently so the player slides
** along walls instead of stopping dead on contact.
*/
static void	move_player(t_game *game, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = game->player.x + dx;
	ny = game->player.y + dy;
	if (game->map.grid[(int)game->player.y][(int)(nx + WALL_MARGIN)] != '1'
		&& game->map.grid[(int)game->player.y][(int)(nx - WALL_MARGIN)] != '1')
		game->player.x = nx;
	if (game->map.grid[(int)(ny + WALL_MARGIN)][(int)game->player.x] != '1'
		&& game->map.grid[(int)(ny - WALL_MARGIN)][(int)game->player.x] != '1')
		game->player.y = ny;
}

/*
** Reads the bitmask of currently held keys and applies the
** corresponding movement or rotation for this frame.
** Strafe directions: A moves left  (-dir_y,  dir_x),
**                    D moves right ( dir_y, -dir_x).
*/
void	handle_movement(t_game *game)
{
	t_player	*p;

	p = &game->player;
	if (game->keys_held & BIT_W)
		move_player(game, p->dir_x * MOVE_SPEED, p->dir_y * MOVE_SPEED);
	if (game->keys_held & BIT_S)
		move_player(game, -p->dir_x * MOVE_SPEED, -p->dir_y * MOVE_SPEED);
	if (game->keys_held & BIT_A)
		move_player(game, p->dir_y * MOVE_SPEED, -p->dir_x * MOVE_SPEED);
	if (game->keys_held & BIT_D)
		move_player(game, -p->dir_y * MOVE_SPEED, p->dir_x * MOVE_SPEED);
	if (game->keys_held & BIT_LEFT && !game->mouse_enabled)
		rotate_player(p, -ROT_SPEED);
	if (game->keys_held & BIT_RIGHT && !game->mouse_enabled)
		rotate_player(p, ROT_SPEED);
}

// Clears the bitmask bit for the released key.
int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys_held &= ~BIT_W;
	if (keycode == KEY_S)
		game->keys_held &= ~BIT_S;
	if (keycode == KEY_A)
		game->keys_held &= ~BIT_A;
	if (keycode == KEY_D)
		game->keys_held &= ~BIT_D;
	if (keycode == KEY_LEFT)
		game->keys_held &= ~BIT_LEFT;
	if (keycode == KEY_RIGHT)
		game->keys_held &= ~BIT_RIGHT;
	return (0);
}

// Sets the bitmask bit for the pressed key, or exits on ESC.
int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_W)
		game->keys_held |= BIT_W;
	if (keycode == KEY_S)
		game->keys_held |= BIT_S;
	if (keycode == KEY_A)
		game->keys_held |= BIT_A;
	if (keycode == KEY_D)
		game->keys_held |= BIT_D;
	if (keycode == KEY_LEFT)
		game->keys_held |= BIT_LEFT;
	if (keycode == KEY_RIGHT)
		game->keys_held |= BIT_RIGHT;
	if (keycode == KEY_TAB)
	{
		game->mouse_enabled = !game->mouse_enabled;
		game->mouse_centered = 0;
		if (game->mouse_enabled)
			mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
