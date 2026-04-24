/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:18:06 by phofer            #+#    #+#             */
/*   Updated: 2025/05/30 18:40:30 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*
#include <stdio.h>

t_list *ft_lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}

int main ()
{
	t_list *tail = NULL;

	t_list *x = ft_lstnew("pineapple");
	t_list *y = ft_lstnew("pizza");

	ft_lstadd_back(&tail, x);
	ft_lstadd_back(&tail, y);
	
	t_list *test = tail;
	while (test)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}

	t_list *tmp;
	while (tail)
	{	
		tmp = tail;
		tail = tail->next;
		free(tmp);
	}
	return 0;
}*/
