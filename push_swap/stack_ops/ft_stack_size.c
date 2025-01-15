/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:02 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 10:11:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	t_stack	*ptr;
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
#include "ft_stack_new.c"
#include "ft_stack_add_front.c"
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
	
	printf("size of list is %i\n", ft_lstsize(head));

	free(node1);
    free(node2);
    free(node3);
	return 1;
}*/