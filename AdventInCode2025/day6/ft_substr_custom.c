/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_custom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:27:09 by thchau            #+#    #+#             */
/*   Updated: 2025/12/06 17:12:10 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc(size_t start, size_t s_len, size_t len)
{
	char	*p;

	if (len > s_len)
		len = s_len;
	if (start >= s_len)
		p = (char *)malloc(1);
	else if (start + len < s_len)
		p = (char *)malloc((len + 1) * sizeof(char));
	else
		p = (char *)malloc((s_len - start + 1) * sizeof(char));
	return (p);
}

char	*ft_substr_custom(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	s_len;

	s_len = ft_strlen(s);
	ptr = ft_alloc(start, s_len, len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			if (s[i] == ' ')
				ptr[j++] = '0';
			else
				ptr[j++] = s[i];
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*#include <stdio.h>
#include "ft_strlen.c"
#include <string.h>
#include <malloc.h>          // Linux
int main()
{
	char s[] = "0123456789";
	char *p = ft_substr(s, 9, 10);
	printf("compare result is %i\n", !strcmp(p, "9"));
	void * p2 = malloc(2);
	printf("p is %s with malloc_usable_size %li\n", p, malloc_usable_size(p));
	printf("expected malloc_usable_size %li\n", malloc_usable_size(p2));
	free(p);
	printf("sizeof(char) is %li\n", sizeof(char));
	return 1;
}*/