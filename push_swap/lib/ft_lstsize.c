/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:02 by thchau            #+#    #+#             */
/*   Updated: 2024/11/23 22:18:02 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	if (lst == NULL)
		return (0);
	ptr = lst;
	count = 0;
	while (ptr)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
/*#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_lstadd_front.c"
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
	
	printf("size of list is %i\n", ft_lstsize(head));

	free(node1);
    free(node2);
    free(node3);
	return 1;
}*/