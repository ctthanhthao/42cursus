/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:49:04 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 10:12:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*#include <stdio.h>
#include "ft_stack_new.c"
#include "ft_stack_add_back.c"
#include "ft_stack_last.c"
void delete (void *data)
{
	*(int *)data = 0;	
}

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
	ft_lstdelone(node1, &delete);
	head = node2;
	tmp = head;
	printf("\nList of node after deleting last node is ");
	while(tmp)
	{
		printf("%i ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	free(node2);
    free(node3);
	return 0;
}*/