/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:21:06 by thchau            #+#    #+#             */
/*   Updated: 2025/02/11 18:43:32 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s)
		return (dest);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char dest[] = "1234567890\0";
	char *src = &dest[2];
	char dest1[] = "1234567890\0";
	char *src1 = &dest1[2];
	int numOfbyte = 4;
	printf("==== before calling function ==========\n");
	printf("dest is %s\n", dest);
	printf("src is %s\n", src);
	printf("dest1 is %s\n", dest1);
	printf("src1 is %s\n", src1);
	ft_memmove(dest, src, numOfbyte);
	memmove(dest1, src1, numOfbyte);
	printf("==== after calling function ==========\n");
	printf("dest is %s\n", dest);
	printf("src is %s\n", src);
	printf("dest1 is %s\n", dest1);
	printf("src1 is %s\n", src1);
	return 1;
}*/