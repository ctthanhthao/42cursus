/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:09 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 19:03:54 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"
#include <stdio.h>

static int	execute(t_stack **st_a, t_stack **st_b, char *ins)
{
	if (ft_strncmp(ins, "sa", 2) == 0)
		swap_top_no_print(st_a);
	else if (ft_strncmp(ins, "sb", 2) == 0)
		swap_top_no_print(st_b);
	else if (ft_strncmp(ins, "pa", 2) == 0)
		push_s2_to_s1(st_a, st_b);
	else if (ft_strncmp(ins, "pb", 2) == 0)
		push_s2_to_s1(st_b, st_a);
	else if (ft_strncmp(ins, "ra", 2) == 0)
		rotate_no_print(st_a);
	else if (ft_strncmp(ins, "rb", 2) == 0)
		rotate_no_print(st_b);
	else if (ft_strncmp(ins, "rrr", 3) == 0)
		both_reverse_rotate_no_print(st_a, st_b);
	else if (ft_strncmp(ins, "rra", 3) == 0)
		reverse_rotate_no_print(st_a);
	else if (ft_strncmp(ins, "rrb", 3) == 0)
		reverse_rotate_no_print(st_b);
	else if (ft_strncmp(ins, "rr", 2) == 0)
		both_rotate_no_print(st_a, st_b);
	else
		return (ft_stack_free(st_a), ft_stack_free(st_b), 0);
	return (1);
}

// Function to read and execute instructions on the stacks
void	execute_ins(t_stack **st_a, t_stack **st_b)
{
	char	*ins;

	while (1)
	{
		ins = get_next_line(0);
		if (!ins)
			break ;
		if (!execute(st_a, st_b, ins))
		{
			free(ins);
			ft_error();
		}
		free(ins);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = ft_process(argc, argv);
	st_b = NULL;
	if (!st_a || ft_checkdup(st_a))
	{
		ft_stack_free(&st_a);
		ft_error();
	}
	if (ft_stack_size(st_a) == 1)
		return (write_intr("OK", ' '),
			ft_stack_free(&st_a), ft_stack_free(&st_b), 0);
	execute_ins(&st_a, &st_b);
	if (is_asc_sorted(st_a) && ft_stack_size(st_b) == 0)
		write_intr("OK", ' ');
	else
		write_intr("KO", ' ');
	return (ft_stack_free(&st_a), ft_stack_free(&st_b), 0);
}
/*
int	main()
{
	int argc = 2;
 	char *argv[] = {"test","2 1"};
	t_stack	*st_a;
	t_stack	*st_b;

	if (argc < 2)
		return (0);
	st_a = ft_process(argc, argv);
	st_b = NULL;
	if (!st_a || ft_checkdup(st_a))
	{
		ft_stack_free(&st_a);
		ft_error();
	}
	if (ft_stack_size(st_a) == 1)
		return (ft_stack_free(&st_a), ft_stack_free(&st_b), 0);
	execute_ins(&st_a, &st_b);
	if (is_asc_sorted(st_a) && ft_stack_size(st_b) == 0)
		write_intr("OK", ' ');
	else
		write_intr("KO", ' ');
	return (ft_stack_free(&st_a), ft_stack_free(&st_b), 0);
}*/