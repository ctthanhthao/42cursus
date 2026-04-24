/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:36:28 by phofer            #+#    #+#             */
/*   Updated: 2025/06/04 17:20:13 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	print_function(int *count, int i, va_list args, const char *phumat)
{
	++i;
	if (phumat[i] == '%')
		print_c(count, '%');
	else if (phumat[i] == 'c')
		print_c(count, va_arg(args, int));
	else if (phumat[i] == 's')
		print_str(count, va_arg(args, char *));
	else if (phumat[i] == 'p')
		print_p(count, va_arg(args, void *));
	else if (phumat[i] == 'd' || phumat[i] == 'i')
		print_num(count, va_arg(args, int));
	else if (phumat[i] == 'u')
		print_u(count, va_arg(args, unsigned int));
	else if (phumat[i] == 'x' || phumat[i] == 'X')
		print_x(count, va_arg(args, unsigned int), phumat[i]);
	else
		print_c(count, phumat[i]);
	return (i);
}

int	ft_printf(const char *phumat, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!phumat)
		return (1);
	i = 0;
	count = 0;
	va_start(args, phumat);
	while (phumat[i])
	{
		if (phumat[i] == '%')
		{
			if (phumat[i + 1] == '\0')
				break ;
			i = print_function(&count, i, args, phumat);
		}
		else
			print_c(&count, phumat[i]);
		++i;
	}
	va_end(args);
	return (count);
}
