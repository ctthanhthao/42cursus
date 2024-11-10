/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:51:01 by thchau            #+#    #+#             */
/*   Updated: 2024/11/10 07:55:40 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*read_and_store(int fd, char *buffer)
{
	char	*tmp;
	char	*read_buf;
	ssize_t	byte_read;
	int		new_line;
	
	read_buf = malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	read_buf[BUFFER_SIZE] = '\0';
	while (1)
	{
		new_line = has_new_line(buffer);
		if (new_line != 1)
		{
			byte_read = read(fd, read_buf, BUFFER_SIZE);
			if (byte_read == -1)
			{
				free(read_buf);
				free(buffer);
				buffer = NULL;
				return (NULL);
			}
			if (byte_read == 0)
				break;
			read_buf[byte_read] = '\0';
			tmp = buffer;
			buffer = ft_strjoin(tmp, read_buf);
			free(tmp);
			if (!buffer)
				return (NULL);
		}
		else
			break;
	}
	free(read_buf);
	return (buffer);
}

static char *extract_line(char **buffer)
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
	{
		free(line);
		return (NULL);
	}
	free(*buffer);
	*buffer = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line && buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}	
	return (line);	
}
/*#include <stdio.h>
#include "get_next_line_utils.c"
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	// int		fd2;
	// int		fd3;

	fd1 = open("1char.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break;
		printf("line [%02d]: %s", i, line);
		free(line);
	// 	line = get_next_line(fd2);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	line = get_next_line(fd3);
	// 	printf("line [%02d]: %s", i, line);
	// 	free(line);
	// 	i++;
	 }
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}*/