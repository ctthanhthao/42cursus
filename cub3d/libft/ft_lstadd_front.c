/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:46:37 by phofer            #+#    #+#             */
/*   Updated: 2025/05/29 14:04:26 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	t_list *head = NULL;

	t_list *x = ft_lstnew("mia");
	t_list *y = ft_lstnew("moma");

	ft_lstadd_front(&head, x);
	ft_lstadd_front(&head, y);
	
	t_list *test = head;
	while (test)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}

	free (x);
	free (y);
	return 0;
}*/