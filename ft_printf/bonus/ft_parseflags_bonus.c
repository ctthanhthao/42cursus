/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseflags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:14:20 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:01:57 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	return (flags);
}

static void	update_width(const char **str, t_flags *flags, va_list args)
{
	if (ft_isdigit(**str))
		flags->width = ft_atoi(str);
	else if (**str == '*')
	{
		flags->width = va_arg(args, int);
		(*str)++;
	}
}

static void	update_precision(const char **str, t_flags *flags, va_list args)
{
	if (**str == '.')
	{
		(*str)++;
		flags->dot = 1;
		if (ft_isdigit(**str))
			flags->precision = ft_atoi(str);
		else if (**str == '*')
		{
			flags->precision = va_arg(args, int);
			(*str)++;
		}
		else
			flags->precision = 0;
	}
}

t_flags	*ft_parseflags(const char **str, va_list args)
{
	t_flags	*flags;

	flags = init_flags();
	if (flags == NULL)
		return (NULL);
	while (**str == '-' || **str == '0' || **str == '#'
		|| **str == ' ' || **str == '+')
	{
		if (**str == '-')
			flags->minus = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '#')
			flags->hash = 1;
		else if (**str == '0')
			flags->zero = 1;
		(*str)++;
	}
	update_width(str, flags, args);
	update_precision(str, flags, args);
	return (flags);
}
