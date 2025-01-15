/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:05:35 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:26:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	if (*lst != NULL)
	{
		new->next = *lst;
	}
	*lst = new;
}
/*#include <stdio.h>
int main()
{
	t_list *head = NULL;
	int data1 = 10;
	int data2 = 20;
	int data3 = 30;
	t_list *node1 = ft_stack_new(&data1);
	t_list *node2 = ft_stack_new(&data2);
	t_list *node3 = ft_stack_new(&data3);
	
	ft_stack_add_front(&head, node1);
	ft_stack_add_front(&head, node2);
	ft_stack_add_front(&head, node3);
	
	t_list *tmp = head;
	while(tmp)
	{
		printf("node is %i\n", *(int*)tmp->content);
		tmp = tmp->next;
	}
	free(node1);
    free(node2);
    free(node3);
	return 1;
}*/