/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:42:47 by thchau            #+#    #+#             */
/*   Updated: 2024/11/29 10:21:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stack_new(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	*(node->content) = content;
	node->next = NULL;
	return (node);
}
/*#include <stdio.h>
int main()
{
	char *s = "Hello World";
	t_list *node = ft_stack_new((char *)s);
	printf("content of node is %s\n", (char *)node->content);
	if (node->next == NULL)
	{
		printf("next of node is null\n");
		free(node);
		return 0;
	}
	return 1;
}*/