/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:32:16 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 10:26:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_arr(char **ar)
{
	int		i;

	if (!ar)
		return ;
	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
	free(ar);
	ar = NULL;
}

char	**ft_clean_arr(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	return (arr);
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