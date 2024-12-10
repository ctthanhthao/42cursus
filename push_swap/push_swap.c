/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:06:21 by thchau            #+#    #+#             */
/*   Updated: 2024/12/10 13:11:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include "lib/common_utils.c"
#include "lib/ft_free.c"
#include "lib/ft_stack_add_back.c"
#include "lib/ft_stack_add_front.c"
#include "lib/ft_stack_last.c"
#include "lib/ft_stack_new.c"
#include "lib/ft_stack_size.c"
#include "lib/ft_split.c"
#include "lib/ft_strlen.c"
#include "lib/ft_strlcpy.c"
#include "lib/sort.c"
#include "lib/stack_ops.c"
#include "lib/ft_checkdup.c"
#include "lib/ft_strncmp.c"
#include "lib/ft_strjoin.c"
#include "lib/ft_strdup.c"
#include "ft_process.c"
#include "lib/ft_error.c"
#include <stdio.h>

void	do_print(t_stack *st)
{
	printf("Items in stack is ");
	while(st)
	{
		printf("%i ", *(st->content));
		st = st->next;
	}
	printf("\n");
}

void	do_sort(t_stack *st_a)
{
	int	stack_size;

	stack_size = ft_stack_size(st_a);
	if (stack_size == 2)
		swap_top(&st_a, 'a');
	else if (stack_size == 3)
		sort_three(st_a);
	else if (stack_size <= 5)
		sort_five(st_a);
	else
		sort_large(st_a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!is_asc_sorted(a))
		do_sort(a);
	ft_free_stack(&a);
	return (0);
}

/*int	main()
{
	int argc = 8;
 	char *argv[] = {"test","1", "5","2", "4", "3", "6", "7"};
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!is_asc_sorted(a))
		do_sort(a);
	ft_free_stack(&a);
	return (0);
}*/
