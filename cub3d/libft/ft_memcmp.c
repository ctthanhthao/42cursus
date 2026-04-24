/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:38:12 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 12:46:51 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*x;
	const unsigned char	*y;
	size_t				i;

	x = (const unsigned char *)s1;
	y = (const unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (x[i] != y[i])
			return (x[i] - y[i]);
		++i;
	}
	return (0);
}
