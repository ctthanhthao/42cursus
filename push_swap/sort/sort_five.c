/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:45:45 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:56:57 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*sort_five(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		min_pos;
	int		stack_a_size;

	stack_b = NULL;
	stack_a_size = ft_stack_size(stack_a);
	while (!is_asc_sorted(stack_a) && stack_a_size > 3)
	{
		min_pos = min_position(stack_a);
		move_to_top(&stack_a, min_pos, stack_a_size, 'a');
		if (!is_asc_sorted(stack_a))
			push_b(&stack_a, &stack_b);
		stack_a_size--;
	}
	if (stack_a_size == 3 && !is_asc_sorted(stack_a))
		stack_a = sort_three(stack_a);
	while (ft_stack_size(stack_b) != 0)
		push_a(&stack_a, &stack_b);
	return (stack_a);
}
