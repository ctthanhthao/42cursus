/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_l_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:47:48 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 09:57:39 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

// Helper function to calculate the operations for a single item
static char	**calculate_ops_for_item(int a_item, t_stack *st_b,
	int pos_in_a, t_st_data *data)
{
	char	*ops_in_a;
	char	*ops_in_b;
	char	**best_moves;
	int		c_total_moves;

	ops_in_a = seq_moves_to_top(data->st_a_size, pos_in_a);
	ops_in_b = seq_moves_to_top(data->st_b_size, find_pos_in_b(st_b, a_item));
	best_moves = NULL;
	c_total_moves = calculate_ops(ops_in_a, ops_in_b);
	if (data->total_moves == 0 || c_total_moves < data->total_moves)
	{
		best_moves = ft_alloc(2);
		best_moves[0] = ft_strdup(ops_in_a);
		best_moves[1] = ft_strdup(ops_in_b);
		data->total_moves = c_total_moves;
	}
	free(ops_in_a);
	free(ops_in_b);
	return (best_moves);
}

static char	**clone_arr(char **ori, char **copy)
{
	ft_clean_arr(copy);
	copy[0] = ft_strdup(ori[0]);
	copy[1] = ft_strdup(ori[1]);
	return (copy);
}

char	**next_item_position(t_stack *st_a, t_stack *st_b)
{
	t_st_data	data;
	t_stack		*cur;
	int			pos_in_a;
	char		**cheapest_moves;
	char		**current_moves;

	data.st_a_size = ft_stack_size(st_a);
	data.st_b_size = ft_stack_size(st_b);
	data.total_moves = 0;
	cheapest_moves = ft_alloc(2);
	cur = st_a;
	pos_in_a = 0;
	while (cur)
	{
		current_moves = calculate_ops_for_item(*(cur->content), st_b, pos_in_a,
				&data);
		if (current_moves)
		{
			cheapest_moves = clone_arr(current_moves, cheapest_moves);
			ft_free_arr(current_moves);
		}
		pos_in_a++;
		cur = cur->next;
	}
	return (cheapest_moves);
}
