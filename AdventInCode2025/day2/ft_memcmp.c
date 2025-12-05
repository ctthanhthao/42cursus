/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:13:31 by thchau            #+#    #+#             */
/*   Updated: 2025/12/02 14:11:28 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n > 0 && (p1 || p2))
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	const char s1[] = "1234567890\0";
	const char s2[] = "1234";
	char s3[] = {0, 0, 127, 0};
	char s4[] = {0, 0, 42, 0};
	int n = 8;
	int n1 = 4;
	int r1 = ft_memcmp(s1, s2, n);
	printf("==== after ft_memcmp ==========\n");
	printf("The result is %i\n", r1);
	
	int r2 = memcmp(s1, s2, n);
	printf("==== after memcmp ==========\n");
	printf("The result is %i\n", r2);
	
	r1 = ft_memcmp(s3, s4, n1);
	printf("==== after ft_memcmp ==========\n");
	printf("The result is %i\n", r1);
	
	r2 = memcmp(s3, s4, n1);
	printf("==== after memcmp ==========\n");
	printf("The result is %i\n", r2);
	return 1;
}*/