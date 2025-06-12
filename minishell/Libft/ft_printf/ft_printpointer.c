/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:26:44 by amarcz            #+#    #+#             */
/*   Updated: 2024/10/04 12:23:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printpointer(void *ptr, t_flags flags)
{
	unsigned long	address;
	int				len;

	if (!ptr)
		return (ft_printstring("(nil)", flags));
	len = 0;
	address = (unsigned long)ptr;
	flags.hash = 1;
	len += ft_converthexa(address, 0, flags);
	return (len);
}
