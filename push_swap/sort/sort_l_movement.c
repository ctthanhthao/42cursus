/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_l_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:36:43 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 10:28:11 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_to_top(t_stack **stack, int num_pos, int stack_size, char s_name)
{
	if (num_pos == 1)
		rotate(stack, s_name);
	else if (num_pos == (stack_size - 1))
		reverse_rotate(stack, s_name);
	else if (num_pos > stack_size - num_pos)
	{
		while (num_pos < stack_size)
		{
			reverse_rotate(stack, s_name);
			num_pos++;
		}
	}
	else
	{
		while (num_pos > 0)
		{
			rotate(stack, s_name);
			num_pos--;
		}
	}
}

static int	find_pos_in_a(t_stack *sb, int num)
{
	t_stack	*tmp;
	int		pos;
	int		i;

	if (num > max(sb) || num < min(sb))
		return (min_position(sb));
	tmp = sb;
	pos = 0;
	i = 0;
	while (tmp && tmp->next)
	{
		if (num > *(tmp->content) && num < *(tmp->next->content))
		{
			pos = i + 1;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	move_min_to_top(t_stack **st)
{
	int	min_pos;

	min_pos = min_position(*st);
	move_to_top(st, min_pos, ft_stack_size(*st), 'a');
}

t_stack	*move_b_to_a(t_stack *st_a, t_stack *st_b, int st_b_size)
{
	int	top_b;
	int	pos_in_a;
	int	st_a_size;	

	st_a_size = ft_stack_size(st_a);
	while (st_b_size > 0)
	{
		top_b = *(st_b->content);
		pos_in_a = find_pos_in_a(st_a, top_b);
		move_to_top(&st_a, pos_in_a, st_a_size, 'a');
		push_a(&st_a, &st_b);
		st_a_size++;
		st_b_size--;
	}
	if (!is_asc_sorted(st_a))
		move_min_to_top(&st_a);
	return (st_a);
}
