/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:16:54 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:54:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pt;

	pt = (const unsigned char *)s;
	while (n > 0)
	{
		if (*pt == (unsigned char)c)
			return ((void *)pt);
		pt++;
		n--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "Hello World!!";
	char c = 'o';
	int n = 3;
	
	char *r = (char *)ft_memchr(s, c, n);
	printf("==== after ft_memchr\n");
	printf("Character '%c' found at position: %li\n", c, r-s);
	char *r1 = (char *)memchr(s, c, n);
	printf("==== after memchr\n");
	printf("Character '%c' found at position: %li\n", c, r1-s);
	return 0;
}*/