/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:15:23 by thchau            #+#    #+#             */
/*   Updated: 2024/12/10 09:18:55 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define ASC 	1
#define DESC	0

typedef struct s_stack
{
	int				*content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_pair
{
	int		pos;
	char	*ops;
}		t_pair;

int		ft_isdigit(int c);
size_t	ps_atoi(const char *ptr);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	write_intr(char *str, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_by_comma(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
void	ft_error(void);
int		ft_checkdup(t_stack *a);

int		ops_len(char **ops);
void	swap_top(t_stack **stack, char c);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack, char c);
void	reverse_rotate(t_stack **stack, char c);
void	both_rotate(t_stack **st_a, t_stack **st_b);
void	both_reverse_rotate(t_stack **st_a, t_stack **st_b);
int		is_asc_sorted(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	sort_large(t_stack *stack);

t_stack	*ft_process(int argc, char **argv);
t_stack	*ft_stack_new(int content);
t_stack	*ft_stack_last(t_stack *lst);
void	ft_stack_add_front(t_stack **lst, t_stack *new);
void	ft_free_stack(t_stack **lst);
void 	ft_free_arr(char **ar);
int		ft_stack_size(t_stack *lst);
void	ft_stack_add_back(t_stack **lst, t_stack *new);

#endif