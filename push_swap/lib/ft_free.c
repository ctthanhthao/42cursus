/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:32:16 by thchau            #+#    #+#             */
/*   Updated: 2024/12/10 10:51:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_free_arr(char **ar)
{
	char	*n1;

	if (!ar)
		return ;
	while (*ar)
	{
		n1 = *ar;
		ar++;
		free(n1);
		n1 = NULL;
	}
	*ar = NULL;
}

void	ft_free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst == NULL || lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}
/*#include <stdio.h>
#include "ft_stack_new.c"
#include "ft_stack_add_back.c"
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
	ft_lstclear(&head, &delete);
	if (head == NULL)
	{
		printf("\nList of node has been cleared \n");
	}
	
	//free(node1);
	//free(node2);
    //free(node3);
	return 0;
}*/