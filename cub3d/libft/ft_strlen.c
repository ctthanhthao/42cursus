/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:11:52 by phofer            #+#    #+#             */
/*   Updated: 2025/05/21 18:20:38 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		++i;
	}
	return (i);
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%d\n", ft_strlen(argv[1]));
	}
	else
		printf("Invalid input");
}*/
