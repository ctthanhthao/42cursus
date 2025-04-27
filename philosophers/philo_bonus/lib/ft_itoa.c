/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:38:49 by thchau            #+#    #+#             */
/*   Updated: 2025/04/27 12:41:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static char	*ft_strdup(const char *src)
{
	size_t	s_len;
	size_t	idx;
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

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_convert_to_str(char *s, int n)
{
	int	n_len;

	n_len = ft_count_digits(n);
	s[n_len] = '\0';
	if (n < 0)
	{
		*s = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		s[--n_len] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)safe_malloc((ft_count_digits(n) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	return (ft_convert_to_str(s, n));
}
/*#include <stdio.h>
int main(void)
{
	int num[5] = {0, -34343, 343424, -2147483648, 2147483647};
	for (int i = 0; i < 5; i++)
	{
		char *s = ft_itoa(num[i]);
		printf("Result is %s\n", s);
		free(s);
	}
	return 0;
}*/