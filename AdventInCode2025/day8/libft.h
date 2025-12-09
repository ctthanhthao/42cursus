/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:29:11 by thchau            #+#    #+#             */
/*   Updated: 2025/12/08 19:06:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_edge {
    double dist;
    int i;
    int j;
}   t_edge;

typedef struct s_dsu
{
	int parent;
	int size;
} t_dsu;


char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
void			*ft_memcpy(void *dest, const void *src, size_t n);
unsigned int	ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
void			free_split(char **arr);
unsigned long long	ft_atoll(const char *ptr);

#endif // End of include guard