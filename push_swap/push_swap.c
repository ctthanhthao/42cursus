/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:06:21 by thchau            #+#    #+#             */
/*   Updated: 2024/12/04 20:45:31 by thchau           ###   ########.fr       */
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


/*int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!is_sorted(a, ASC))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}*/

int	main()
{
	int argc = 4;
	char *argv[] = {"test", "12","96","56"};
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free_stack(&a);
		ft_error();
	}
	if (!is_sorted(a, ASC))
		tiny_sort(a);
	ft_free_stack(&a);
	return (0);
}
