/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:29:02 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 11:02:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack, int is_asc)
{
	t_stack *tmp;

	if (!stack || ft_stack_size(stack) == 1)
		return (1);
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (is_asc == 1 && *(tmp->content) > *(tmp->next->content))
			return (0);
		if (is_asc == 0 && *(tmp->content) < *(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	min_position(t_stack *st)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = st;
	min = *(st->content);
	pos = 0;
	i = 0;
	tmp = tmp->next;
	while (tmp)
	{
		if (min < *(tmp->content))
		{
			min = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	tiny_sort(t_stack *stack_a)
{
	int	stack_a_size;
	int	min_pos;
	t_stack *stack_b;

	stack_b = NULL;
	while (!is_sorted(stack_a, ASC))
	{
		stack_a_size = ft_stack_size(stack_a);
		if (stack_a_size ==0)
			break;
		min_pos = min_position(stack_a);
		if (min_pos == 1)
			swap_top(&stack_a, 'a');
		else if (min_pos == stack_a_size - 1)
			reverse_rotate(&stack_a, 'a');
		else if (min_pos > (stack_a_size - min_pos))
			while (min_pos < stack_a_size)
			{
				reverse_rotate(&stack_a, 'a');
				min_pos++;
			}		
		else
			while (min_pos > 0)
			{
				rotate(&stack_a, 'a');
				min_pos--;
			}	
		push_b(&stack_a, &stack_b);
	}
	while (ft_stack_size(stack_b) != 0)
		push_a(&stack_a, &stack_b);
}