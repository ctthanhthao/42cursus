/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:33:43 by thchau            #+#    #+#             */
/*   Updated: 2024/09/20 20:41:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	if (size)
	{
		if (src_len >= size)
			len = size - 1;
		else
			len = src_len;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (src_len);
}
/*#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char dest[] = "12345\0";
	char src[] = "abce\0";
	char dest1[] = "12345\0";
	char src1[] = "abce\0";
	int len = strlcpy(dest, src, 5);
	printf("dest is %s from strlcpy is %i\n",dest, len);
	int len1 = ft_strlcpy(dest1, src1, 5);
	printf("dest1 is %s from ft_strlcpy is %i\n",dest1, len1);
	return 1;
}
Note: Since strlcpy is not standard lib, run in terminal
> gcc -o main ft_strlcpy.c -lbsd
*/