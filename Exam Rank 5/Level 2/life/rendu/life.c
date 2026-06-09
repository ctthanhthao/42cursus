/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:23:56 by thchau            #+#    #+#             */
/*   Updated: 2026/06/09 22:52:57 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int		init_game(t_game *game, char *argv[])
{
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int iter = atoi(argv[3]);
	if (h <= 0 || w <= 0 || iter < 0)
		return (FAILURE);
	game->board = (char **) malloc (h * sizeof(char *));
	if (!game->board)
		return (FAILURE);
	for (int i = 0; i < h; i++)
	{
		game->board[i] = (char *) malloc (w * sizeof(char));
		if (!game->board[i])
		{
			free_board(game);
			return (FAILURE);
		}
		for (int j = 0; j < w; j++)
			game->board[i][j] = ' ';
	}	
	game->height = h;
	game->width = w;
	game->iterations = iter;
	return (SUCCESS);
}

void	free_board(t_game *game)
{
	if (game || !game->board)
		return;
	for(int i = 0; i < game->height; i++)
	{
		if (game->board[i])
		{
			free(game->board[i]);
			game->board[i] = NULL;	
		}
	}
	free(game->board);
	game->board = NULL;
}

void	fill_board(t_game *game)
{
	char c;
	int draw = 0;
	int i = 0;
	int j = 0;
	while (read(STDIN_FILENO, &c, 1) == 1)
	{
		if (c == 'w' && i > 0)
			i--;
		else if (c == 's' && i < game->height - 1)
			i++;
		else if (c == 'a' && j > 0)
			j--;
		else if (c == 'd' && j < game->width - 1)
			j++;
		else if (c == 'x')
			draw = !draw;
		else
			continue;
		if (draw == 1)
			game->board[i][j] = 'O';
	}
}

char	**new_board(t_game *game)
{
	char **tmp = (char **) malloc (game->height * sizeof(char *));
	if (!tmp)
		return NULL;
	for (int i = 0; i < game->height; i++)
	{
		tmp[i] = (char *) malloc (game->width * sizeof(char));
		if (!tmp[i])
		{
			while (i--)
				free (tmp[i]);
			free(tmp);
			return (NULL);
		}
		for (int j = 0; j < game->width; j++)
			tmp[i][j] = ' ';
	}
	return (tmp);
}

void	print_board(t_game *game)
{
	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			putchar(game->board[i][j]);
		}
		putchar('\n');
	}
}

static int count_neighbor(t_game *game, int i, int j)
{
	int count = 0;
	if (i > 0 && game->board[i - 1][j] == 'O')
		count++;
	if (i + 1 < game->height && game->board[i + 1][j] == 'O')
		count++;
	if (j > 0 && game->board[i][j - 1] == 'O')
		count++;
	if (j + 1 < game->width && game->board[i][j + 1] == 'O')
		count++;
	if (i - 1 >= 0 && j - 1 >= 0 && game->board[i - 1][j - 1] == 'O')
		count++;
	if (i - 1 >= 0 && j + 1 < game->width && game->board[i - 1][j + 1] == 'O')
		count++;
	if (i + 1 < game->height && j - 1 >= 0 && game->board[i + 1][j - 1] == 'O')
		count++;
	if (i + 1 < game->height && j + 1 < game->width && game->board[i + 1][j + 1] == 'O')
		count++;
	return (count);
}

static int play(t_game *game)
{
	char **re = new_board(game);
	if (!re)
		return (FAILURE);
	int numOfNeighbors = 0;
	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			numOfNeighbors = count_neighbor(game, i, j);
			if (game->board[i][j] == 'O' && (numOfNeighbors == 2 || numOfNeighbors == 3))
				re[i][j] = 'O';
			else if (numOfNeighbors == 3)
				re[i][j] = 'O';
			else
				re[i][j] = ' ';
		}
	}
	free_board(game);
	game->board = re;
	return (SUCCESS);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return(1);
	t_game game;
	if (init_game(&game, argv) == FAILURE)
		return (1);
	fill_board(&game);
	for (int i = 1; i <= game.iterations; i++)
	{
		if (play(&game) == FAILURE)
		{
			free_board(&game);
			return (1);	
		}
	}
	print_board(&game);
	free_board(&game);
	return (0);
}