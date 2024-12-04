/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:50:15 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 10:12:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "ft_lstnew.c"
#include "ft_lstadd_back.c"
#include "ft_lstlast.c"
#include "ft_lstsize.c"
#include "common_utils.c"
#include "ft_lstadd_front.c"
#include "ft_lstdelone.c"
#include "ft_strlen.c"

int main()
{
	t_stack *head = NULL;
	t_stack *head2 = NULL;
	int num_arr[10] = {10, 20, 30, 40, 70, 90, 100, 42, 1, 45};
	int num_arr2[2] = {5, 2};
	// 
	int i = 0;
	t_stack *node ;

	while (i < 10)
	{
		node = ft_stack_new(&num_arr[i]);
		ft_stack_add_back(&head, node);
		i++;
	}
	i = 0;
	// while (i < 2)
	// {
	// 	node = ft_lstnew(&num_arr2[i]);
	// 	ft_stack_add_back(&head2, node);
	// 	i++;
	// }
	t_stack *tmp = head;
	printf("List of stack_a is \n");
	while(tmp)
	{
		printf("%i ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = head2;
	printf("List of stack_b is \n");
	while(tmp)
	{
		printf("%i ", *(int*)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	int value = 30;
	int times = 3;
	// reverse_rotate(&head, 'a');
	// reverse_rotate(&head, 'a');
	// reverse_rotate(&head, 'a');
	 t_stack *tmp1;
	
	// printf("AFTER rr %i times- List of node in stack a is \n", times);
	// while(tmp1)
	// {
	// 	printf("%i ", *(int*)tmp1->content);
	// 	tmp1 = tmp1->next;
	// }
	// printf("\n");
	printf("TEST push_b ==============\n");
	push_b(&head, &head2);
	// rotate(&head2, 'b');
	//printf("TEST push_a ==============\n");
	//push_a(&head, &head2);
	printf("AFTER pb =========== \n List of node in stack a is ");
	tmp1 = head;
	while(tmp1)
	{
		printf("%i ", *(int*)tmp1->content);
		tmp1 = tmp1->next;
	}
	printf("\n");
	printf("List of node in stack b is ");
	tmp1 = head2;
	while(tmp1)
	{
		printf("%i ", *(int*)tmp1->content);
		tmp1 = tmp1->next;
	}
	printf("TEST swap stack a ==============\n");
	swap_top(&head, 'a');
	// rotate(&head2, 'b');
	//printf("TEST push_a ==============\n");
	//push_a(&head, &head2);
	printf("AFTER sa =========== \n List of node in stack a is ");
	tmp1 = head;
	while(tmp1)
	{
		printf("%i ", *(int*)tmp1->content);
		tmp1 = tmp1->next;
	}
	printf("\n");
	printf("Trying to free node \n");
	tmp1 = head;
	while(tmp1)
	{
		head = head->next;
		free(tmp1);
		tmp1 = head;
	}
	tmp1 = head2;
	while(tmp1)
	{
		head2 = head2->next;
		free(tmp1);
		tmp1 = head2;
	}
	printf("\n");
	printf("DONE");
	printf("\n");
	return 1;
}