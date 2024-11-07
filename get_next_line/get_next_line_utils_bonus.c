/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:01:29 by thchau            #+#    #+#             */
/*   Updated: 2024/11/07 06:41:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*result;
	
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = (char *)malloc(l1 + l2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, l1);
	ft_memcpy(result + l1, s2, l2 + 1);
	return (result);
}

char	*ft_strdup(char *src)
{
	unsigned int	s_len;
	unsigned int	idx;
	char	*ptr;

	s_len = ft_strlen(src);
	ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx <= s_len)
	{
		ptr[idx] = src[idx];
		idx++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

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
