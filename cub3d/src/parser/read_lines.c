/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:32:11 by thchau            #+#    #+#             */
/*   Updated: 2026/04/23 16:22:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

/*
** Count lines in file
*/
static int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}

/*
** Remove newline at the end of line
*/
static void	remove_newline(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

/**
 * @brief This function reads an entire configuration file into memory as an 
 * array of strings, with each line stored as a separate element. It returns a 
 * dynamically allocated null-terminated array of strings, making it easy for 
 * the calling code to iterate through all lines sequentially.
 */
char	**read_file_lines(const char *filename, int *line_count)
{
	int		fd;
	int		i;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (log_err("File not found."), NULL);
	*line_count = count_lines(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (*line_count + 1));
	if (!lines)
		return (close(fd), NULL);
	i = -1;
	while (++i < *line_count)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			return (close(fd), NULL);
		remove_newline(lines[i]);
	}
	lines[i] = NULL;
	return (get_next_line(fd), close(fd), lines);
}
