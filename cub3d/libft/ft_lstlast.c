/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:11:33 by phofer            #+#    #+#             */
/*   Updated: 2025/05/29 14:16:24 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int main () 
{
	t_list *x = ft_lstnew("fourtytwo");
	t_list *y = ft_lstnew("is");
	t_list *z = ft_lstnew("amazeballs");

	x->next = y;
	y->next = z;

	t_list *last = ft_lstlast(x);

	if (last && last->content)
		printf("%s\n", (char *)last->content);
	else
		printf("Error");

	free(x);
	free(y);
	free(z);

	return 0;
} */