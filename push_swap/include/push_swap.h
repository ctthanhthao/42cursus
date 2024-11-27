/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:15:23 by thchau            #+#    #+#             */
/*   Updated: 2024/11/24 15:45:10 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define ASC 	1
#define DESC	0

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}					t_list;

int		ps_isdigit(int c);
size_t	ps_atoi(const char *ptr);
void	swap_top(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));

#endif