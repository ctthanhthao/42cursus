/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:01:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/20 17:56:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	p_atol(const char *str)
{
	long	result;

	result = 0;
	while (*str)
	{
		if (!is_digit(*str))
		{
			log_error("Only number is allowed.");
			return (INVALID_INPUT);
		}
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result > 2147483647)
	{
		log_error("Number could not exceed INT_MAX");
		return (INVALID_INPUT);
	}
	return (result);
}

static long	ft_atol(const char *str)
{
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		log_error("Negative number is not allowed.");
		return (INVALID_INPUT);
	}
	if (ft_length(str) > 10)
	{
		log_error("Number could not exceed INT_MAX");
		return (INVALID_INPUT);
	}
	return (p_atol(str));
}

static t_error_code	assign_usec(long *dest, char *str)
{
	int	value;

	value = ft_atol(str);
	if (value == INVALID_INPUT)
		return (INVALID_INPUT);
	*dest = value * 1e3;
	return (SUCCESS);
}

t_error_code	parse_input(t_table *tb, char **argv)
{
	int	value;

	value = ft_atol(argv[1]);
	if (value == INVALID_INPUT)
		return (ERROR_PARSE);
	tb->philo_nbr = value;
	if (assign_usec(&tb->time_to_die, argv[2]) == INVALID_INPUT
		|| assign_usec(&tb->time_to_eat, argv[3]) == INVALID_INPUT
		||assign_usec(&tb->time_to_sleep, argv[4]) == INVALID_INPUT)
		return (ERROR_PARSE);
	if (tb->time_to_die < 6e4 || tb->time_to_eat < 6e4
		|| tb->time_to_sleep < 6e4)
		return (log_error("Timestamp must be larger than 60ms"), ERROR_PARSE);
	if (argv[5])
	{
		value = ft_atol(argv[5]);
		if (value == INVALID_INPUT)
			return (ERROR_PARSE);
		tb->nbr_limit_meal = value;
	}
	else
		tb->nbr_limit_meal = -1;
	return (SUCCESS);
}
