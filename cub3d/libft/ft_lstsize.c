/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:04:42 by phofer            #+#    #+#             */
/*   Updated: 2025/05/29 14:17:35 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		++i;
		lst = lst->next;
	}
	return (i);
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

	printf("%d\n", ft_lstsize(x));

	free(x);
	free(y);
	free(z);

	return 0;
}*/