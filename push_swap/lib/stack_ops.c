/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:09 by thchau            #+#    #+#             */
/*   Updated: 2024/11/24 14:02:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list *item;
	t_list *tmp;
	
	if (!stack_b || !*stack_b)
		return ;
	item = ft_lstnew((*stack_b)->content);
	ft_lstadd_front(stack_a, item);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstdelone(tmp, free);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
}

void	swap_top(t_list **stack)
{
	int	*tmp;
	
	if (!stack || !*stack)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*copy;
	t_list	*tmp;
	
	copy = ft_lstnew((*stack)->content);
	ft_lstadd_back(stack, copy);
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstdelone(tmp, free);
}

void	reverse_rotate(t_list **stack)
{
	int	init_val;
	t_list	*new_val;
	t_list	*last;
	t_list	*before_last;
	
	init_val = 0;
	new_val = ft_lstnew(&init_val);
	ft_lstadd_front(stack, new_val);
	last = *stack;
	while (last && last->next)
	{
		if (last->next)
			before_last = last;
		last = last->next;
	}
	new_val->content = last->content;
	before_last->next = NULL;
	free(last);
}
