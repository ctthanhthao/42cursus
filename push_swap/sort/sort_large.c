/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:29:02 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 14:07:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	if (*((*stack_b)->content) < *((*stack_b)->next->content))
		swap_top(stack_b, 'b');
}

t_stack	*sort_large(t_stack *st_a)
{
	t_stack	*st_b;
	char	**moves;
	int		st_a_size;
	int		st_b_size;

	st_b = NULL;
	init_stack_b(&st_a, &st_b);
	st_a_size = ft_stack_size(st_a);
	st_b_size = ft_stack_size(st_b);
	while (st_a_size > 3)
	{
		moves = next_item_position(st_a, st_b);
		sort_l_exec(&st_a, &st_b, moves);
		ft_free_arr(moves);
		st_a_size--;
		st_b_size++;
	}
	if (!is_asc_sorted(st_a))
		st_a = sort_three(st_a);
	return (move_b_to_a(st_a, st_b, st_b_size));
}
