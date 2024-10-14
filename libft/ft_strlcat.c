/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:11:33 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:51:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	copy_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len >= size)
		return (size + s_len);
	copy_len = size - d_len - 1;
	if (copy_len > s_len)
		copy_len = s_len;
	ft_memcpy(dst + d_len, src, copy_len);
	dst[d_len + copy_len] = '\0';
	return (d_len + s_len);
}
/*#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char dest[20] = "12345\0";
	char src[] = "abce\0";
	char dest1[] = "12345\0";
	char src1[] = "abce\0";
	int size = 20;
//	int len = strlcat(dest, src, size);
//	printf("dest is %s from strlcat is %i\n",dest, len);
	int len1 = strlcat(dest1, src1, size);
	printf("dest1 is %s from ft_strlcat is %i\n",dest1, len1);
	return 1;
}*/
/*Note: Since strlcat is not standard lib, run in terminal
> gcc -o main ft_strlcat.c -lbsd
*/