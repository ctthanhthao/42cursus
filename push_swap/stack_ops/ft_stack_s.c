/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:09 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 13:20:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top_no_print(t_stack **st)
{
	int	*tmp;

	if (!st || !*st)
		return ;
	tmp = (*st)->content;
	(*st)->content = (*st)->next->content;
	(*st)->next->content = tmp;
}

void	swap_top(t_stack **st, char c)
{
	swap_top_no_print(st);
	write_intr("s", c);
}
