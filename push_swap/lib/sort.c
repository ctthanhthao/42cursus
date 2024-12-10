/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:29:02 by thchau            #+#    #+#             */
/*   Updated: 2024/12/10 16:17:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_asc_sorted(t_stack *stack)
{
	t_stack *tmp;

	if (!stack || ft_stack_size(stack) == 1)
		return (1);
	tmp = stack;
	while (tmp && tmp->next)
	{
		if (*(tmp->content) > *(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ops_len(char **ops)
{
	int	i;

	i = 0;
	if (!ops || !*ops)
		return (0);
	while (ops[i])
		i++;
	return (i);
}

int	min(t_stack *st)
{
	t_stack	*tmp;
	int		min;

	tmp = st;
	min = *(st->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (min > *(tmp->content))
			min = *(tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int	max(t_stack *st)
{
	t_stack	*tmp;
	int		max;

	tmp = st;
	max = *(st->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (max < *(tmp->content))
			max = *(tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

int	min_position(t_stack *st)
{
	t_stack	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = st;
	min = *(st->content);
	pos = 0;
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (min > *(tmp->content))
		{
			min = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	max_position(t_stack *st)
{
	t_stack	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = st;
	max = *(st->content);
	pos = 0;
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (max < *(tmp->content))
		{
			max = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	find_pos_in_a(t_stack *sb, int num)
{
	t_stack	*tmp;
	int		pos;
	int		i;

	if (num > max(sb) || num < min(sb))
		return (min_position(sb));
	tmp = sb;
	pos = 0;
	i = 0;
	while (tmp && tmp->next)
	{
		if (num > *(tmp->content) && num < *(tmp->next->content))
		{
			pos = i + 1;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	find_pos_in_b(t_stack *sb, int num)
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
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	move_to_top(t_stack **stack, int num_pos, int stack_size, char s_name)
{
	if (num_pos == 1)
		rotate(stack, s_name);
	else if (num_pos == (stack_size - 1))
		reverse_rotate(stack, s_name);
	else if (num_pos > stack_size - num_pos)
	{	
		while (num_pos < stack_size)
		{
			reverse_rotate(stack, s_name);
			num_pos++;
		}
	}		
	else
	{
		while (num_pos > 0)
		{
			rotate(stack, s_name);
			num_pos--;
		}
	}
}

static char	*join_ops(int count, const char *ops_name)
{
	char	*ops;
	char	*tmp;
	
	ops = NULL;
	while (count > 0)
	{
		tmp = ops;
		ops = ft_strjoin_by_comma(tmp, ops_name);
		free(tmp);
		tmp = NULL;
		count--;
	}
	return (ops);
}

char *seq_moves_to_top(int stack_size, int num_pos)
{
	char	*ops;
	char	*tmp;
	
	ops = NULL;
	if (num_pos == 1)
		ops = ft_strdup("r");
	else if (num_pos == (stack_size - 1))
		ops = ft_strdup("rr");
	else if (num_pos > stack_size - num_pos)
		ops = join_ops(stack_size - num_pos, "rr");	
	else
	{
		ops = join_ops(num_pos, "r");	
	}
	return (ops);
}

void	sort_three(t_stack *stack)
{
	t_stack	*e1;
	t_stack	*e2;
	t_stack *e3;
	
	e1 = stack;
	e2 = stack->next;
	e3 = e2->next;
	if (*(e1->content) < *(e2->content) && *(e1->content) < *(e3->content))
	{
		swap_top(&stack, 'a');
		rotate(&stack, 'a');
	}
	else if (*(e1->content) < *(e2->content) && *(e1->content) > *(e3->content))
		reverse_rotate(&stack, 'a');
	else if ((*(e1->content) > *(e2->content) && *(e1->content) > *(e3->content)))
		if (*(e2->content) > *(e3->content))
		{
			swap_top(&stack, 'a');
			reverse_rotate(&stack, 'a');
		}
		else
			rotate(&stack, 'a');
	else
		swap_top(&stack, 'a');
}

void	sort_five(t_stack *stack_a)
{
	t_stack *stack_b;
	int		min_pos;
	int		stack_a_size;

	stack_b = NULL;
	stack_a_size = ft_stack_size(stack_a);
	while (!is_asc_sorted(stack_a) && stack_a_size > 3)
	{
		min_pos = min_position(stack_a);
		move_to_top(&stack_a, min_pos, stack_a_size, 'a');
		if (!is_asc_sorted(stack_a))	
			push_b(&stack_a, &stack_b);
		stack_a_size--;
	}
	if (stack_a_size == 3 && !is_asc_sorted(stack_a))
		sort_three(stack_a);
	while (ft_stack_size(stack_b) != 0)
		push_a(&stack_a, &stack_b);
}

static void	init_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);	
	push_b(stack_a, stack_b);
	if (*((*stack_b)->content) < *((*stack_b)->next->content))
		swap_top(stack_b, 'b');
}

int	*init_moves_arr(int pos_a, int pos_b)
{
	int	*moves_arr;

	moves_arr = (int *)malloc(2 * sizeof(int));
	if (moves_arr == NULL)
		return (NULL);
	moves_arr[0] = pos_a;
	moves_arr[1] = pos_b;
	return (moves_arr);
}

static int	count_ops(char *ops)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (!ops)
		return (i);
	while (ops[i])
	{
		if (ops[i] == ',')
		count++;
	}
	return (count);	
}

int	calculate_t_ops(char *ops_a, char *ops_b)
{
	int	count_ops_a;
	int	count_ops_b;
	
	count_ops_a = count_ops(ops_a);
	count_ops_b = count_ops(ops_b);
	if (!count_ops_a)
		return (count_ops_b + 1);
	if (!count_ops_b)
		return (count_ops_a + 1);
	if (ft_strncmp(ops_a, ops_b, 2) != 0)
		return (count_ops_a + count_ops_b + 1);
	if (count_ops_a > count_ops_b)
		return (count_ops_a + 1);
	return (count_ops_b) + 1;
}

char	**next_chosen_num_pos(t_stack *stack_a, t_stack *stack_b)
{
	int	top_a;
	int	pos_in_b;
	int	pos_in_a;
	int	stack_a_size;
	int	stack_b_size;
	int	total;
	char	**cheapest_moves;
	t_stack *cur;
	char	*ops_in_a;
	char	*ops_in_b;
	
	cur = stack_a;
	pos_in_a = 0;
	total = 0;
	stack_a_size = ft_stack_size(stack_a);
	stack_b_size = ft_stack_size(stack_b);
	cheapest_moves = (char **)malloc(2 * sizeof(char *));
	while (cur)
	{
		top_a = *(cur->content);
		pos_in_b = find_pos_in_b(stack_b, top_a);
		ops_in_a = seq_moves_to_top(stack_a_size, pos_in_a);
		ops_in_b = seq_moves_to_top(stack_b_size, pos_in_b);
		if (total == 0 || total > calculate_t_ops(ops_in_a, ops_in_b))
		{
			free(cheapest_moves[0]);
			free(cheapest_moves[1]);
			cheapest_moves[0] = ft_strdup(ops_in_a);
			cheapest_moves[1] = ft_strdup(ops_in_b);
			total = calculate_t_ops(ops_in_a, ops_in_b);
		}
		free(ops_in_a);
		free(ops_in_b);
		pos_in_a++;
		cur = cur->next;
	}
	return (cheapest_moves);
}

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

static void	sub_execute(t_stack **st_a, t_stack **st_b, char **ops_in_a, char **ops_in_b)
{
	int	ops_a_len;
	int	ops_b_len;
	
	ops_a_len = ops_len(ops_in_a);
	ops_b_len = ops_len(ops_in_b);
	
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

static void	execute(t_stack **st_a, t_stack **st_b, char **moves)
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
	len_a = ops_len(ops_in_a);
	len_b = ops_len(ops_in_b);
	if (len_a == 0 && len_b == 0)
	{
		push_b(st_a, st_b);
		return ;
	}
	if (len_a == 0)
		do_r_or_rr(st_b, ops_in_b, 'b');
	else if (len_b == 0)
		do_r_or_rr(st_a, ops_in_a, 'a');
	else
		sub_execute(st_a, st_b, ops_in_a, ops_in_b);
	push_b(st_a, st_b);
}

void	move_min_to_top(t_stack **st)
{
	int	min_pos;
	
	min_pos = min_position(*st);
	move_to_top(st, min_pos, ft_stack_size(*st), 'a');
}

static void move_b_to_a(t_stack *st_a, t_stack *st_b, int st_b_size)
{
	int	top_b;
	int	num_a;
	int	pos_in_a;
	int	st_a_size;	
	
	st_a_size = ft_stack_size(st_a);
	while (st_b_size > 0)
	{
		top_b = *(st_b->content);
		pos_in_a = find_pos_in_a(st_a, top_b);
		move_to_top(&st_a, pos_in_a, st_a_size, 'a');
		push_a(&st_a, &st_b);
		st_a_size++;
		st_b_size--;	
	}
	if (!is_asc_sorted(st_a))
		move_min_to_top(&st_a);
}

void	sort_large(t_stack *st_a)
{
	t_stack *st_b;
	char	**moves;
	int		st_a_size;
	int		st_b_size;
	int		top_b;
	int		num_a;

	st_b = NULL;
	init_stack_b(&st_a, &st_b);
	st_a_size = ft_stack_size(st_a);
	st_b_size = ft_stack_size(st_b);
	while (st_a_size > 3)
	{
		moves = next_chosen_num_pos(st_a, st_b);
		execute(&st_a, &st_b, moves);  
		free(moves);
		st_a_size--;
		st_b_size++;
	}
	if (!is_asc_sorted(st_a))
		sort_three(st_a);
	move_b_to_a(st_a, st_b, st_b_size);
	free(st_b);
}