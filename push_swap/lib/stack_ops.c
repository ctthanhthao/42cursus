/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:09 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 11:31:20 by thchau           ###   ########.fr       */
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
	*s2 = tmp->next;
	tmp->next = NULL;
	free(tmp);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push_s2_to_s1(stack_a, stack_b);
	write_intr("p", 'a');
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_s2_to_s1(stack_b, stack_a);
	write_intr("p", 'b');
}

void	swap_top(t_stack **stack, char c)
{
	int	*tmp;
	
	if (!stack || !*stack)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write_intr("s", c);
}

// rotate elements: first element becomes the last element
void	rotate(t_stack **stack, char c)
{
	int		i;
	t_stack	*start;
	t_stack	*last;
	
	if (!stack || !*stack || ft_stack_size(*stack) == 1)
		return ;
	i = 1;
	start = *stack;
	last = ft_stack_last(*stack);
	last->next = *stack;
	*stack = start->next;
	start->next = NULL;
	write_intr("r", c);
}

// reverse rotate elements: last element becomes the first element
void	reverse_rotate(t_stack **stack, char c)
{
	int		i;
	t_stack	*last;
	t_stack	*before_last;
	
	if (!stack || !*stack || ft_stack_size(*stack) == 1)
		return ;
	i = 1;
	last = *stack;
	while (last->next)
	{
		if (last->next->next == NULL)
			before_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
	write_intr("rr", c);
}
