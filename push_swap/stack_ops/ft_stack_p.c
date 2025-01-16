/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:24:32 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 12:52:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_s2_to_s1(t_stack **s1, t_stack **s2)
{
	t_stack	*item;
	t_stack	*tmp;

	if (!s2 || !*s2)
		return ;
	item = ft_stack_new(*((*s2)->content));
	ft_stack_add_front(s1, item);
	tmp = *s2;
	*s2 = (*s2)->next;
	tmp->next = NULL;
	if (tmp->content)
		free(tmp->content);
	free(tmp);
	if (!*s2)
		*s2 = NULL;
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
