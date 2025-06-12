/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_determin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:40:53 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/29 15:49:05 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_formspec(int c)
{
	if (c == '-' || c == '0' || c == '#' || c == '+'
		|| c == '.' || c == '*' || c == ' ')
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_ft_isdigit(c) || ft_is_formspec(c));
}

int	ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'x' || c == 'X' || c == 'p'
		|| c == 'i' || c == 'd' || c == '%' || c == 'u')
		return (1);
	return (0);
}
