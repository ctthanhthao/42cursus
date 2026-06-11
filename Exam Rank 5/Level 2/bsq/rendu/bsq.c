/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:12:45 by thchau            #+#    #+#             */
/*   Updated: 2026/06/11 05:44:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_map
{
	int rows;
	int cols;
	char empty;
	char obs;
	char full;
	char **grid;
} t_map;

static void remove_newline(char *s)
{
	int	i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	if(s[i] == '\n')
		s[i] = '\0';
}

int parse_header(char *line, t_map *m)
{
	int i = 0;
	int rows = 0;
	
	while(line[i] && line[i] >= '0' && line[i] <= '9')
		rows = rows * 10 + (line[i++] - '0');
	if (rows <= 0 || !line[i] || !line[i + 1] || !line[i + 2] || line[i + 3])
		return (0);
	m->rows = rows;
	m->empty = line[i];
	m->obs = line[i + 1];
	m->full = line[i + 2];
	if (m->empty == m->obs || m->empty == m->full || m->obs == m->full)
		return (0);
	return (1);
}

int	read_grid(FILE *fp, t_map *m)
{
	char	*line = NULL;
	size_t	n = 0;
	int		i = 0;
	
	m->cols = 0;
	while (i < m->rows && getline(&line, &n, fp) != -1)
	{
		remove_newline(line);
		if (m->cols == 0)
			m->cols = strlen(line);
		if ((int)strlen(line) != m->cols)
			return (0);
		for (int j = 0; line[j]; j++)
			if(line[j] != m->empty && line[j] != m->obs)
				return (0);
		m->grid[i] = strdup(line);
		if(!m->grid[i])
			return (0);
		i++;
	}
	return (i == m->rows);
}

void	solve_bsq(t_map *m)
{
	int	*prev = calloc(m->cols, sizeof(int));
	int	*cur = calloc(m->cols, sizeof(int));
	
	int	best = 0;
	int	bi = 0;
	int bj = 0;
	
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			if (m->grid[j][j] == m->obs)
				cur[j] = 0;
			else if (i == 0 && j == 0)
				cur[j] = 1;
			else
			{
				int min = prev[j];
				if (cur[j - 1] < min) min = cur[j - 1];
				if (prev[j - 1] < min) min = prev[j - 1];
				cur[j] = min + 1;
			}
			if (cur[j] > best)
			{
				best = cur[j];
				bi = i;
				bj = j;
			}
		}
		for (int k = 0; k < m->cols; k++)
			prev[k] = cur[k];
	}
	free(prev);
	free(cur);
	
	for (int i = 0; i < best; i++)
	{
		for (int j = 0; j < best; j++)
			m->grid[bi-i][bj - j] = m->full;
	}
}

void	print_map(t_map *map)
{
	for (int i = 0; i < map->rows; i++)
		printf("%s\n", map->grid[i]);
}

int main (int argc, char **argv)
{
	FILE	*fp;
	t_map	m;
	char	*line = NULL;
	size_t	n = 0;
	
	if (argc == 1)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");
	if (!fp)
		return (1);
	if (getline(&line, &n, fp) == -1)
		return (1);
	remove_newline(line);
	if (!parse_header(line, &m))
	{
		free(line);
		return (1);
	}
	if (!read_grid(fp, &m))
	{
		free(line);
		return (1);
	}
	solve_bsq(&m);
	print_map(&m);
}