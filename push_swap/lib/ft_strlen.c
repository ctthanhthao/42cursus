/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:12:42 by thchau            #+#    #+#             */
/*   Updated: 2024/11/28 14:06:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
/*#include <stdio.h>
int main()
{
	char *s = "asdsfsdgdgdgjdkfjgkfjgfjgdfklgfhgfklgjdkflgjdlkgjdl";
	printf("length is %li", ft_strlen(s));
	return 1;
}*/