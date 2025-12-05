/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:29:11 by thchau            #+#    #+#             */
/*   Updated: 2025/12/02 14:45:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *src);
void			*ft_memcpy(void *dest, const void *src, size_t n);
unsigned int	ft_strlen(const char *s);
void	free_split(char **arr);

unsigned long long	ft_atoll(const char *ptr);
char	*ft_lltoa(unsigned long long n);
char	**ft_split(char const *s, char c);
int	ft_memcmp(void *s1, void *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
#endif // End of include guard