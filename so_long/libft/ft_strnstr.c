/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:30:57 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:53:17 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (l_len <= 0)
		return ((char *)big);
	while (*big && len >= l_len)
	{
		if (ft_memcmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*#include <bsd/string.h>
#include <stdio.h>
int main()
{
	char s[] = "Hello World!!";
	char c[] = "l";
	int n = 7;
	
	char *r = (char *)ft_strnstr(s, c, n);
	printf("==== after ft_strnstr\n");
	printf("Result is '%s'\n", r);
	char s1[] = "Hello World!!";
	char *r1 = (char *)strnstr(s1, c, n);
	printf("==== after strnstr\n");
	printf("Result is '%s'\n", r1);
	return 0;
}*/