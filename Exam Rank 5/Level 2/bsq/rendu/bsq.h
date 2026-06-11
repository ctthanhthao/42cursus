/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:50:45 by thchau            #+#    #+#             */
/*   Updated: 2026/06/11 08:57:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

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

int		read_grid(FILE *fp, t_map *m);
int		parse_header(char *line, t_map *m);
void	remove_newline(char *s);
void	solve_bsq(t_map *m);
void	clean_up(t_map *m);
void	print_map(t_map *map);
#endif