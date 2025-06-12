/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:49:53 by amarcz            #+#    #+#             */
/*   Updated: 2024/11/18 12:47:16 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> //for size_t
# include <unistd.h>
# include <stdlib.h>

//#include <stdio.h>

//struct

typedef struct s_split_next
{
	size_t	start;
	size_t	length;
}				t_split_next;

//lists

typedef struct s_llist
{
	void			*content;
	struct s_llist	*next;
}	t_llist;

void			*ft_memset(void *s, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isspace(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_printf(const char *format, ...);

//Lists

t_llist			*ft_lstnew(void *content);
void			ft_lstadd_front(t_llist **lst, t_llist *new);
int				ft_lstsize(t_llist *lst);
t_llist			*ft_lstlast(t_llist *lst);
void			ft_lstadd_back(t_llist **lst, t_llist *new);
void			ft_lstdelone(t_llist *lst, void (*del)(void *));
void			ft_lstclear(t_llist **lst, void (*del)(void *));
void			ft_lstiter(t_llist *lst, void (*f)(void *));
t_llist			*ft_lstmap(t_llist *lst, void *(*f)(void *),
					void (*del)(void *));

#endif // LIBFT_H
