/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:24:40 by thchau            #+#    #+#             */
/*   Updated: 2024/09/24 12:11:21 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		ptr[n] = (unsigned char)c;
	}
	return (s);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "thao test234\0";
	char s1[] = "thao test\0";
	ft_memset(s, 'V', 10);
	memset(s1, 'V', 10);
	printf("the result s is %s\n", s);
	printf("the result s1 is %s\n", s1);
	return 1;
}*/
