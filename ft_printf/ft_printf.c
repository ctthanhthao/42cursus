/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:41:50 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 15:56:03 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
// #include "bonus/ft_handlehex_bonus.c"
// #include "bonus/ft_handlechars_bonus.c"
// #include "bonus/ft_handlenum_bonus.c"
// #include "bonus/ft_handlenum_helper_bonus.c"
// #include "bonus/ft_handlehex_helper_bonus.c"
// #include "bonus/ft_handleptr_bonus.c"
// #include "bonus/ft_parseflags_bonus.c"
// #include "bonus/ft_process_bonus.c"
// #include "lib/ft_atoi.c"
// #include "lib/ft_itoa.c"
// #include "lib/ft_isdigit.c"
// #include "lib/ft_memcpy.c"
// #include "lib/ft_memset.c"
// #include "lib/ft_strreverse.c"
// #include "lib/ft_printchars.c"
// #include "lib/ft_strdup.c"
// #include "lib/ft_strlen.c"
// #include "lib/ft_utils.c"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (str == NULL)
		return (ft_printchars(str));
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_process(&str, args);
		}
		else
			count += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
