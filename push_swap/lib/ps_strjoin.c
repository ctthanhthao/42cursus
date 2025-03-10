/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:14:12 by thchau            #+#    #+#             */
/*   Updated: 2025/01/14 19:21:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strjoin_by_comma(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[j++] = s1[i];
		i++;
	}
	if (j > 0)
		result[j++] = ',';
	i = 0;
	while (s2 && s2[i])
	{
		result[j++] = s2[i];
		i++;
	}
	return (result[j] = 0, result);
}

char	*ps_strjoin(int count, const char *ops_name)
{
	char	*ops;
	char	*tmp;

	ops = NULL;
	while (count > 0)
	{
		tmp = ops;
		ops = ft_strjoin_by_comma(tmp, ops_name);
		free(tmp);
		tmp = NULL;
		count--;
	}
	return (ops);
}
/*#include <stdio.h>
int main()
{
	char *s1 = "Hello World";
	char *s2 = " I'm here";
	char *r = ft_strjoin(s1, s2);
	printf("Result is %s\n", r);
	return 1;
}*/