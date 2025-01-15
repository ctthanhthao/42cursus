/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:26:36 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 09:38:10 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	process(t_stack **stack, int val2, int val3)
{
	if (val2 > val3)
	{
		swap_top(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else
		rotate(stack, 'a');
}

t_stack	*sort_three(t_stack *stack)
{
	t_stack	*e1;
	t_stack	*e2;
	t_stack	*e3;

	e1 = stack;
	e2 = stack->next;
	e3 = e2->next;
	if (*(e1->content) < *(e2->content) && *(e1->content) < *(e3->content))
	{
		swap_top(&stack, 'a');
		rotate(&stack, 'a');
	}
	else if (*(e1->content) < *(e2->content) && *(e1->content) > *(e3->content))
		reverse_rotate(&stack, 'a');
	else if ((*(e1->content) > *(e2->content)
			&& *(e1->content) > *(e3->content)))
		process(&stack, *(e2->content), *(e3->content));
	else
		swap_top(&stack, 'a');
	return (stack);
}
