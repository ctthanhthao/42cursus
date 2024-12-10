/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:26:15 by thchau            #+#    #+#             */
/*   Updated: 2024/12/09 11:21:23 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char *s1 = "hello world";
	char *s2 = "hella";
	char n = 5;
	int r = ft_strncmp(s1, s2, n);
	printf("the result from ft_strncmp is %d\n", r);
	int r1 = strncmp(s1, s2, n);
	printf("the result from strncmp is %d\n", r1);
	return 0;
}*/