/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_nals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:27:04 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 13:53:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = (int *)malloc(sizeof(int));
	if (node->content == NULL)
	{
		free(node);
		return (NULL);
	}
	*(node->content) = content;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_stack_last(*lst);
		ptr->next = new;
	}
}

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
	}
	*lst = new;
}

t_stack	*ft_stack_last(t_stack *lst)
{
	t_stack	*last;

	last = lst;
	while (last && last->next)
	{
		last = last->next;
	}
	return (last);
}

int	ft_stack_size(t_stack *lst)
{
	t_stack	*ptr;
	int		count;

	if (lst == NULL)
		return (0);
	ptr = lst;
	count = 0;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
