/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_l_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:40:05 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 11:31:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	do_r_or_rr(t_stack **st, char **ops, char st_name)
{
	int	i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(ops[i], "r", 2) == 0)
			rotate(st, st_name);
		else
			reverse_rotate(st, st_name);
		i++;
	}
}

static void	do_rr_or_rrr(t_stack **st_a, t_stack **st_b, char **ops)
{
	int	i;

	i = 0;
	while (ops[i])
	{
		if (ft_strncmp(ops[i], "r", 2) == 0)
			both_rotate(st_a, st_b);
		else
			both_reverse_rotate(st_a, st_b);
		i++;
	}
}

static void	sub_execute(t_stack **st_a, t_stack **st_b, char **ops_in_a,
	char **ops_in_b)
{
	int	ops_a_len;
	int	ops_b_len;

	ops_a_len = ft_arrlen(ops_in_a);
	ops_b_len = ft_arrlen(ops_in_b);
	if (ft_strncmp(ops_in_a[0], ops_in_b[0], 2) != 0)
	{
		do_r_or_rr(st_a, ops_in_a, 'a');
		do_r_or_rr(st_b, ops_in_b, 'b');
	}
	else
	{
		if (ops_a_len > ops_b_len)
		{
			do_rr_or_rrr(st_a, st_b, ops_in_b);
			do_r_or_rr(st_a, &ops_in_a[ops_b_len], 'a');
		}
		else
		{
			do_rr_or_rrr(st_a, st_b, ops_in_a);
			do_r_or_rr(st_b, &ops_in_b[ops_a_len], 'b');
		}
	}
}

static void	push_b_then_free(t_stack **st_a, t_stack **st_b, char **ops_in_a,
	char **ops_in_b)
{
	push_b(st_a, st_b);
	ft_free_arr(ops_in_a);
	ft_free_arr(ops_in_b);
}

void	sort_l_exec(t_stack **st_a, t_stack **st_b, char **moves)
{
	char	**ops_in_a;
	char	**ops_in_b;
	int		len_a;
	int		len_b;

	ops_in_a = NULL;
	ops_in_b = NULL;
	if (ft_strlen(moves[0]) > 0)
		ops_in_a = ft_split(moves[0], ',');
	if (ft_strlen(moves[1]) > 0)
		ops_in_b = ft_split(moves[1], ',');
	len_a = ft_arrlen(ops_in_a);
	len_b = ft_arrlen(ops_in_b);
	if (len_a == 0 && len_b == 0)
	{
		push_b_then_free(st_a, st_b, ops_in_a, ops_in_b);
		return ;
	}
	if (len_a == 0)
		do_r_or_rr(st_b, ops_in_b, 'b');
	else if (len_b == 0)
		do_r_or_rr(st_a, ops_in_a, 'a');
	else
		sub_execute(st_a, st_b, ops_in_a, ops_in_b);
	push_b_then_free(st_a, st_b, ops_in_a, ops_in_b);
}
