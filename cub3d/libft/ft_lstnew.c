/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:36:53 by phofer            #+#    #+#             */
/*   Updated: 2025/05/28 19:53:04 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
/*
#include <stdio.h>

int	main(void)
{
	int		num = 420;
	t_list	*node;

	node = ft_lstnew(&num);
	if (node)
	{
		printf("Node content: %d\n", *(int *)(node->content));
		printf("Next pointer: %p\n", (void *)node->next);
	}
	else
		printf("Memory allocation failed.\n");

	// Clean up
	free(node);
	return (0);
}*/