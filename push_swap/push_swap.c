/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:06:21 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 18:47:32 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
/*#include "lib/common_utils.c"
#include "lib/ft_free.c"
#include "lib/ps_opslen.c"
#include "lib/ps_strjoin.c"
#include "stack_ops/ft_stack_add_back.c"
#include "stack_ops/ft_stack_add_front.c"
#include "stack_ops/ft_stack_last.c"
#include "stack_ops/ft_stack_new.c"
#include "stack_ops/ft_stack_size.c"
#include "stack_ops/ft_stack_p.c"
#include "stack_ops/ft_stack_r.c"
#include "stack_ops/ft_stack_rr.c"
#include "stack_ops/ft_stack_s.c"
#include "stack_ops/ft_min_max.c"
#include "stack_ops/ft_stack_free.c"
#include "lib/ft_split.c"
#include "lib/ft_strlen.c"
#include "lib/ft_strlcpy.c"
#include "sort/sort_five.c"
#include "sort/sort_l_execution.c"
#include "sort/sort_l_movement.c"
#include "sort/sort_l_selection.c"
#include "sort/sort_large.c"
#include "sort/sort_three.c"
#include "stack_ops/ft_checkdup.c"
#include "lib/ft_strncmp.c"
#include "lib/ft_strdup.c"
#include "ft_process.c"
#include "lib/ft_error.c"
#include "lib/ft_alloc.c"
#include <stdio.h>*/

void	do_sort(t_stack *st_a)
{
	int	stack_size;

	stack_size = ft_stack_size(st_a);
	if (stack_size == 2)
		swap_top(&st_a, 'a');
	else if (stack_size == 3)
		st_a = sort_three(st_a);
	else if (stack_size <= 5)
		st_a = sort_five(st_a);
	else
		st_a = sort_large(st_a);
	ft_stack_free(&st_a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_stack_free(&a);
		ft_error();
	}
	if (!is_asc_sorted(a))
		do_sort(a);
	else
		ft_stack_free(&a);
	return (0);
}
/*
int	main()
{
	int argc = 2;
 	char *argv[] = {"test","2 1 3 6 5 8 4"};
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_stack_free(&a);
		ft_error();
	}
	if (!is_asc_sorted(a))
		do_sort(a);
	else
		ft_stack_free(&a);
	return (0);
}*/
