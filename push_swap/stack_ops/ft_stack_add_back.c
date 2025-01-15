/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:28:01 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:26:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
/*#include <stdio.h>
#include "ft_stack_new.c"
#include "ft_stack_add_front.c"
#include "ft_lstlast.c"
int main()
{
	t_list *head = NULL;
	int data1 = 10;
	int data2 = 20;
	int data3 = 30;
	t_list *node1 = ft_stack_new(&data1);
	t_list *node2 = ft_stack_new(&data2);
	t_list *node3 = ft_stack_new(&data3);
	
	ft_stack_add_back(&head, node1);
	ft_stack_add_back(&head, node2);
	ft_stack_add_back(&head, node3);
	t_list *tmp = head;
	printf("List of node is ");
	while(tmp)
	{
		printf("%i ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	free(node1);
    free(node2);
    free(node3);
	return 1;
}*/