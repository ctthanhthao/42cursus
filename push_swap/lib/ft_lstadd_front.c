/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:05:35 by thchau            #+#    #+#             */
/*   Updated: 2024/11/23 22:17:13 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
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
	t_list *node1 = ft_lstnew(&data1);
	t_list *node2 = ft_lstnew(&data2);
	t_list *node3 = ft_lstnew(&data3);
	
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);
	
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