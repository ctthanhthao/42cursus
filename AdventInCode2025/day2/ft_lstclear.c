/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:32:16 by thchau            #+#    #+#             */
/*   Updated: 2025/12/02 14:05:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*#include <stdio.h>
#include "ft_lstnew.c"
#include "ft_lstadd_back.c"
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