/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_l_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:47:48 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 10:30:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*seq_moves_to_top(int stack_size, int num_pos)
{
	char	*ops;

	ops = NULL;
	if (num_pos == 1)
		ops = ft_strdup("r");
	else if (num_pos == (stack_size - 1))
		ops = ft_strdup("rr");
	else if (num_pos > stack_size - num_pos)
		ops = ps_strjoin(stack_size - num_pos, "rr");
	else
		ops = ps_strjoin(num_pos, "r");
	return (ops);
}

static int	find_pos_in_b(t_stack *sb, int num)
{
	t_stack	*tmp;
	int		pos;
	int		i;

	if (num > max(sb) || num < min(sb))
		return (max_position(sb));
	tmp = sb;
	pos = 0;
	i = 0;
	while (tmp && tmp->next)
	{
		if (num < *(tmp->content) && num > *(tmp->next->content))
		{
			pos = i + 1;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static int	calculate_ops(char *ops_a, char *ops_b)
{
	int	count_ops_a;
	int	count_ops_b;

	count_ops_a = ps_opslen_by_comma(ops_a);
	count_ops_b = ps_opslen_by_comma(ops_b);
	if (!count_ops_a)
		return (count_ops_b + 1);
	if (!count_ops_b)
		return (count_ops_a + 1);
	if (ft_strncmp(ops_a, ops_b, 2) != 0)
		return (count_ops_a + count_ops_b + 1);
	if (count_ops_a > count_ops_b)
		return (count_ops_a + 1);
	return (count_ops_b + 1);
}

/*static char	**find_cheapest_moves(char **cheapest_moves, int st_a_size,
				int st_b_size, int *total_ops, int pos_in_a, int pos_in_b)
{
	char	*ops_in_a;
	char	*ops_in_b;
	int		total;

	ops_in_a = seq_moves_to_top(st_a_size, pos_in_a);
	ops_in_b = seq_moves_to_top(st_b_size, pos_in_b);
	total = calculate_ops(ops_in_a, ops_in_b);
	if (total_ops == 0 || *total_ops > total)
	{
		cheapest_moves = ft_clean_arr(cheapest_moves);
		cheapest_moves[0] = ft_strdup(ops_in_a);
		cheapest_moves[1] = ft_strdup(ops_in_b);
		total_ops = &total;
	}
	free(ops_in_a);
	free(ops_in_b);
	return (cheapest_moves);
}*/

char	**next_item_position(t_stack *stack_a, t_stack *stack_b)
{
	int		top_a;
	int		pos_in_b;
	int		pos_in_a;
	int		stack_a_size;
	int		stack_b_size;
	int		total;
	char	*ops_in_a;
	char	*ops_in_b;
	char	**cheapest_moves;
	t_stack	*cur;

	cur = stack_a;
	pos_in_a = 0;
	total = 0;
	stack_a_size = ft_stack_size(stack_a);
	stack_b_size = ft_stack_size(stack_b);
	cheapest_moves = ft_alloc(2);
	while (cur)
	{
		top_a = *(cur->content);
		pos_in_b = find_pos_in_b(stack_b, top_a);
		ops_in_a = seq_moves_to_top(stack_a_size, pos_in_a);
		ops_in_b = seq_moves_to_top(stack_b_size, pos_in_b);
		if (total == 0 || total > calculate_ops(ops_in_a, ops_in_b))
		{
			cheapest_moves = ft_clean_arr(cheapest_moves);
			cheapest_moves[0] = ft_strdup(ops_in_a);
			cheapest_moves[1] = ft_strdup(ops_in_b);
			total = calculate_ops(ops_in_a, ops_in_b);
		}
		free(ops_in_a);
		free(ops_in_b);
		pos_in_a++;
		cur = cur->next;
	}
	return (cheapest_moves);
}
