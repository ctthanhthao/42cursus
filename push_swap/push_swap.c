/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:06:21 by thchau            #+#    #+#             */
/*   Updated: 2024/11/24 14:13:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
//#include "libft/ft_atoi.c"
//#include "libft/ft_isdigit.c"
#include <stdio.h>

void	exit_error()
{
	write(2, "Error\n", 6);
	exit(0);
}

int	check_int_range(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = 0;
	while(*str)
	{
		result = result * 10 + *str - '0';
		if (result > MAX_INT && *(str + 1) == '\0')
			break;
		else if (result > MAX_INT)
			return (0);
		str++;
	}
	result = result * sign;
	if (result > MAX_INT || result < MIN_INT)
		return (0);
	return (1);
}

int	is_integer(const char *str)
{
	char		*endptr;

	if (str == NULL || *str == '\0')
		return (0);
	strtol(str, &endptr, 10);
	if (*endptr == '\0')
		return (check_int_range(str));
	return (0);
}

int	arg_is_num(char **arg)
{
	int	i;
	int	j;
	int	num;
	
	i = 1;
	while (arg[i])
	{
		if (is_integer(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **input)
{
	int	i;
	int	j;
	long long	num1;
	long long num2;
	
	i = 1;
	while (input[i])
	{
		num1 = ps_atoi(input[i]);
		j = i + 1;
		while (input[j])
		{
			num2 = ps_atoi(input[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(char **input)
{
	if (!arg_is_num(input))
		return (0);
	if (check_duplicates(input))
		return (0);
	return (1);
}


int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!validate_input(argv))
		exit_error();
	do_sort(argv);
	return (0);
}
