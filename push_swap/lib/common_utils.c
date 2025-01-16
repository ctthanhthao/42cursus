/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:54:29 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 14:07:56 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_asc_sorted(t_stack *stack)
{
	t_stack	*tmp;

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

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ps_atoi(const char *str)
{
	int				sign;
	long long int	i;

	i = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		ft_error();
	return (sign * i);
}

void	write_intr(char *str, char c)
{
	write(1, str, ft_strlen(str));
	if (c != ' ')
		write(1, &c, 1);
	write(1, "\n", 1);
}
