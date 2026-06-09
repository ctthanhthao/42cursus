/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:17:11 by thchau            #+#    #+#             */
/*   Updated: 2026/06/09 15:08:36 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_HPP
#define LIFE_HPP

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct s_game
{
	int width;
	int height;
	int iterations;
	int draw;
	char **board;	
} t_game;

int		init_game(t_game *game, char *argv[]);
void	fill_board(t_game *game);
void	free_board(t_game *game);
char	**new_board(t_game *game);
void	print_board(t_game *game);


#endif