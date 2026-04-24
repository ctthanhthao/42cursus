/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:38:15 by phofer            #+#    #+#             */
/*   Updated: 2025/05/24 11:37:35 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*r;
	size_t				i;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	p = (unsigned char *)dest;
	r = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = r[i];
		++i;
	}
	return (dest);
}
