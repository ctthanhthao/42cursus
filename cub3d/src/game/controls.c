/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:16:13 by phofer            #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Mouse look is disabled in the mandatory build; handler is a no-op.
int	mouse_move(int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	(void)game;
	return (0);
}
