/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:09 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:27:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top(t_stack **st, char c)
{
	int	*tmp;

	if (!st || !*st)
		return ;
	tmp = (*st)->content;
	(*st)->content = (*st)->next->content;
	(*st)->next->content = tmp;
	write_intr("s", c);
}
