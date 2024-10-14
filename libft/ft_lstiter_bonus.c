/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:40:57 by thchau            #+#    #+#             */
/*   Updated: 2024/09/23 12:10:01 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst == NULL || f == NULL)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
/*#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_lstadd_back.c"
#include "ft_lstlast.c"
void print_data (void *data)
{
	printf("data is %i\n", *(int *)data);	
}

int main()
{
	t_list *head = NULL;
	int data1 = 10;
	int data2 = 20;
	int data3 = 30;
	t_list *node1 = ft_lstnew(&data1);
	t_list *node2 = ft_lstnew(&data2);
	t_list *node3 = ft_lstnew(&data3);
	
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	t_list *tmp = head;
	printf("List of node is ");
	while(tmp)
	{
		printf("%i ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	ft_lstiter(head, &print_data);
	free(node1);
	free(node2);
    free(node3);
	return 0;
}*/