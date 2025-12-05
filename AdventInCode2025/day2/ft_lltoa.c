/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:38:49 by thchau            #+#    #+#             */
/*   Updated: 2025/12/02 13:48:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(unsigned long long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_convert_to_str(char *s, unsigned long long n)
{
	int	n_len;

	n_len = ft_count_digits(n);
	s[n_len] = '\0';
	while (n > 0)
	{
		s[--n_len] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_lltoa(unsigned long long n)
{
	char	*s;
	
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)malloc((ft_count_digits(n) + 1) * sizeof(char));
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