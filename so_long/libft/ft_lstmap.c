/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:10:24 by thchau            #+#    #+#             */
/*   Updated: 2024/09/24 12:22:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			while (new_lst)
			{
				node = new_lst->next;
				del(new_lst->content);
				free(new_lst);
				new_lst = node;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
/*#include <stdio.h>
#include "ft_lstnew_bonus.c"
#include "ft_lstadd_front_bonus.c"
#include "ft_lstclear_bonus.c"
#include "ft_lstadd_back_bonus.c"
#include "ft_lstlast_bonus.c"
#include "ft_lstdelone_bonus.c"
void *ft_increase_char(void *c)
{
	int *new_val = malloc(sizeof(int));
	if (new_val == NULL)
		return NULL;
	*new_val = *(int *)c + 2;
	return new_val;
}

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
	t_list *new_lst = ft_lstmap(head, &ft_increase_char, &delete);
	printf("List of node is ");
	while(new_lst)
	{
		printf("%i ", *(int*)new_lst->content);
		new_lst = new_lst->next;
	}
	ft_lstclear(&head, &delete);
	ft_lstclear(&new_lst, &delete);
	return 0;
}*/