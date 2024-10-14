/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:01:16 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 16:00:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char s[] = "testssssss\0";
	char s1[] = "testssssss\0";
	ft_bzero(s, 3);
	bzero(s1, 3);
	printf("the result s is %s\n", s);
	printf("the result s1 is %s\n", s1);
	return 1;
}*/