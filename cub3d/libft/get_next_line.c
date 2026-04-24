/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:14:53 by phofer            #+#    #+#             */
/*   Updated: 2025/06/20 16:58:36 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

static char	*trim_buf(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buf;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buf = ft_calloc(ft_strlen(buffer + i + 1) + 1, sizeof(char));
	if (!new_buf)
		return (free(buffer), NULL);
	j = 0;
	++i;
	while (buffer[i])
		new_buf[j++] = buffer[i++];
	free(buffer);
	return (new_buf);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = ft_calloc(i + (buffer[i] == '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		++i;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*buff;
	ssize_t	bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !buff)
		return (free(buffer), free(buff), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(buff), NULL);
		if (bytes == 0)
			break ;
		buff[bytes] = '\0';
		buffer = ft_strjoin_free(buffer, buff);
		if (!buffer)
			return (free(buff), NULL);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = trim_buf(buffer);
	return (line);
}
/*
#include <fcntl.h>     // open
#include <stdio.h>     // printf, perror
#include <stdlib.h>    // exit
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_num = 1;

	// Check for correct usage
	if (argc > 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error opening file");
			return (1);
		}
	}
	else
	{
		fd = 0; // stdin
		printf("Reading from standard input (Ctrl+D to end):\n");
	}

	// Read and print each line until EOF
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d: %s", line_num++, line);
		free(line);
	}

	// Close file descriptor
	close(fd);
	return (0);
}
*/