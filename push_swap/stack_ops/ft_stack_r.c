/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:21:24 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 13:05:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_no_print(t_stack **st)
{
	t_stack	*start;
	t_stack	*last;

	if (!st || !*st || ft_stack_size(*st) == 1)
		return ;
	start = *st;
	last = ft_stack_last(*st);
	if (last == start)
		return ;
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

void	both_rotate_no_print(t_stack **st_a, t_stack **st_b)
{
	rotate_no_print(st_a);
	rotate_no_print(st_b);
}

void	both_rotate(t_stack **st_a, t_stack **st_b)
{
	both_rotate_no_print(st_a, st_b);
	write_intr("rr", ' ');
}
