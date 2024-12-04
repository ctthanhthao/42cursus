/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:22:37 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 10:12:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "include/push_swap.h"

int	is_sorted(const t_stack **stack, int is_asc)
{
	if (!stack || !*stack || ft_stack_size(stack) == 1)
		return (1);
	while (*stack && (*stack)->next)
	{
		if (is_asc == 1 && *((*stack)->content) > *((*stack)->next->content))
			return (0);
		if (is_asc == 0 && *((*stack)->content) < *((*stack)->next->content))
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}

void	do_sort(char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*new_node;
	t_stack	*top;
	t_stack	*last;
	t_stack	*next;
	
	i = 1;
	while (argv[i])
	{
		new_node = ft_stack_new(ps_atoi(argv[i]));
		ft_stack_add_back(&stack_a, new_node);
	}
	while (!is_sorted(stack_a, ASC))
	{
		top = stack_a;
		next = stack_a->next;
		last = ft_stack_last(stack_a);
		if (*(top->content) > *(next->content))
		{
			if (*(top->content) > *(last->content))
			{
				rotate(&stack_a, 'a');
				write(1, "ra", 2);
			}
			else 
			{
				swap_top(&stack_a, 'a');
				write(1, "sa", 2);
			}
			write(1, "\n", 1);
		}
		else if (*(top->content) < *(next->content))
		{
			if (*(top->content) < *(last->content))
			{
				push_b(&stack_a, &stack_b);
				write(1, "pb", 2);
			}
			else 
			{
				swap_top(&stack_a, 'a');
				write(1, "sa", 2);
			}
			write(1, "\n", 1);
		}
	}
}*/
