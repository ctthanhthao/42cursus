/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:51:01 by thchau            #+#    #+#             */
/*   Updated: 2024/11/11 21:30:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	has_new_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*join_buffer(char *buffer, char *read_buf)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_strjoin(tmp, read_buf);
	free(tmp);
	tmp = NULL;
	return (buffer);
}

static char	*read_and_store(int fd, char **buffer)
{
	char	*read_buf;
	ssize_t	byte_read;

	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	read_buf[BUFFER_SIZE] = '\0';
	while (!has_new_line(buffer[fd]))
	{
		byte_read = read(fd, read_buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(read_buf);
			return (free(buffer[fd]), buffer[fd] = NULL, NULL);
		}
		if (byte_read == 0)
			break ;
		read_buf[byte_read] = '\0';
		buffer[fd] = join_buffer(buffer[fd], read_buf);
		if (!buffer[fd])
			return (NULL);
	}
	free(read_buf);
	return (buffer[fd]);
}

static char	*extract_line(char **buffer)
{
	char			*line;
	char			*tmp;
	unsigned int	len;

	len = 0;
	line = NULL;
	if (!*buffer || !**buffer)
		return (NULL);
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	if ((*buffer)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *buffer, len);
	line[len] = '\0';
	tmp = ft_strdup(*buffer + len);
	if (!tmp)
		return (free(line), line = NULL, NULL);
	free(*buffer);
	*buffer = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_and_store(fd, buffer);
	if (!buffer[fd] || buffer[fd][0] == 0)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = extract_line(&buffer[fd]);
	if (!line && buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	return (line);
}
