/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:46:40 by thchau            #+#    #+#             */
/*   Updated: 2024/11/11 19:12:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_free_ptr(char *ptr);
unsigned int	ft_strlen(const char *s);
#endif