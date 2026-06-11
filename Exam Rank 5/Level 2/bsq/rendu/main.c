/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:56:20 by thchau            #+#    #+#             */
/*   Updated: 2026/06/11 08:56:32 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
	{
		fclose(fp);
		return (1);
	}
	remove_newline(line);
	if (!parse_header(line, &m))
	{
		free(line);
		fclose(fp);
		return (1);
	}
	if (!read_grid(fp, &m))
	{
		free(line);
		clean_up(&m);
		fclose(fp);
		return (1);
	}
	fclose(fp);
	free(line);
	solve_bsq(&m);
	print_map(&m);
	clean_up(&m);
	return (0);
}
