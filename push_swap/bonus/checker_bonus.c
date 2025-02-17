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

static int	execute(t_stack **st_a, t_stack **st_b, char *ins)
{
	if (ft_strncmp(ins, "ss\n", 3) == 0)
		swap_top_both_stacks(st_a, st_b);
	else if (ft_strncmp(ins, "sa\n", 3) == 0)
		swap_top_no_print(st_a);
	else if (ft_strncmp(ins, "sb\n", 3) == 0)
		swap_top_no_print(st_b);
	else if (ft_strncmp(ins, "pa\n", 3) == 0)
		push_s2_to_s1(st_a, st_b);
	else if (ft_strncmp(ins, "pb\n", 3) == 0)
		push_s2_to_s1(st_b, st_a);
	else if (ft_strncmp(ins, "ra\n", 3) == 0)
		rotate_no_print(st_a);
	else if (ft_strncmp(ins, "rb\n", 3) == 0)
		rotate_no_print(st_b);
	else if (ft_strncmp(ins, "rrr\n", 4) == 0)
		both_reverse_rotate_no_print(st_a, st_b);
	else if (ft_strncmp(ins, "rra\n", 4) == 0)
		reverse_rotate_no_print(st_a);
	else if (ft_strncmp(ins, "rrb\n", 4) == 0)
		reverse_rotate_no_print(st_b);
	else if (ft_strncmp(ins, "rr\n", 3) == 0)
		both_rotate_no_print(st_a, st_b);
	else
		return (ft_stack_free(st_a), ft_stack_free(st_b), 0);
	return (1);
}

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
	execute_ins(&st_a, &st_b);
	if (is_asc_sorted(st_a) && ft_stack_size(st_b) == 0)
		write_intr("OK", ' ');
	else
		write_intr("KO", ' ');
	return (ft_stack_free(&st_a), ft_stack_free(&st_b), 0);
}
