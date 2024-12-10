/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:09 by thchau            #+#    #+#             */
/*   Updated: 2024/12/10 16:22:22 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_s2_to_s1(t_stack **s1, t_stack **s2)
{
	t_stack *item;
	t_stack *tmp;
	
	if (!s2 || !*s2)
		return ;
	item = ft_stack_new(*((*s2)->content));
	ft_stack_add_front(s1, item);
	tmp = *s2;
	*s2 = (*s2)->next;
	tmp->next = NULL;
	free(tmp);
}

void	push_a(t_stack **st_a, t_stack **st_b)
{
	push_s2_to_s1(st_a, st_b);
	write_intr("p", 'a');
}

void	push_b(t_stack **st_a, t_stack **st_b)
{
	push_s2_to_s1(st_b, st_a);
	write_intr("p", 'b');
}

void	swap_top(t_stack **st, char c)
{
	int	*tmp;
	
	if (!st || !*st)
		return ;
	tmp = (*st)->content;
	(*st)->content = (*st)->next->content;
	(*st)->next->content = tmp;
	write_intr("s", c);
}
void	rotate_no_print(t_stack **st)
{
	int		i;
	t_stack	*start;
	t_stack	*last;
	
	if (!st || !*st || ft_stack_size(*st) == 1)
		return ;
	i = 1;
	start = *st;
	last = ft_stack_last(*st);
	last->next = *st;
	*st = start->next;
	start->next = NULL;
}

// rotate elements: first element becomes the last element
void	rotate(t_stack **st, char c)
{
	rotate_no_print(st);
	write_intr("r", c);
}

void	reverse_rotate_no_print(t_stack **st)
{
	int		i;
	t_stack	*last;
	t_stack	*before_last;
	
	if (!st || !*st || ft_stack_size(*st) == 1)
		return ;
	i = 1;
	last = *st;
	while (last->next)
	{
		if (last->next->next == NULL)
			before_last = last;
		last = last->next;
	}
	last->next = *st;
	*st = last;
	before_last->next = NULL;
}

// reverse rotate elements: last element becomes the first element
void	reverse_rotate(t_stack **st, char c)
{
	reverse_rotate_no_print(st);
	write_intr("rr", c);
}

void	both_reverse_rotate(t_stack **st_a, t_stack **st_b)
{
	reverse_rotate_no_print(st_a);
	reverse_rotate_no_print(st_b);
	write_intr("rr", ' ');
}

void	both_rotate(t_stack **st_a, t_stack **st_b)
{
	rotate_no_print(st_a);
	rotate_no_print(st_b);
	write_intr("rrr", ' ');
}
