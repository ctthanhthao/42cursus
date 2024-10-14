/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:53 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:53:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (result * sign);
}
/*#include <stdio.h>
#include <stdlib.h>
int main()
{
	char s[] = "\t\r -2434df4dfdg";
	char s1[] = "\t\r -2434df4fgff";
	int r = ft_atoi(s);
	printf("==== after ft_atoi\n");
	printf("Result is '%i' and str is %s\n", r, s);
	int r1 = atoi(s1);
	printf("==== after atoi\n");
	printf("Result is '%i' and str is %s\n", r1, s1);
	return 0;
}*/
