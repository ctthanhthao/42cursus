/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:23:27 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:24:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min(t_stack *st)
{
	t_stack	*tmp;
	int		min;

	tmp = st;
	min = *(st->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (min > *(tmp->content))
			min = *(tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max(t_stack *st)
{
	t_stack	*tmp;
	int		max;

	tmp = st;
	max = *(st->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (max < *(tmp->content))
			max = *(tmp->content);
		tmp = tmp->next;
	}
	return (max);
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
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (min > *(tmp->content))
		{
			min = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	max_position(t_stack *st)
{
	t_stack	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = st;
	max = *(st->content);
	pos = 0;
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (max < *(tmp->content))
		{
			max = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}
