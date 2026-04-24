/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:11 by phofer            #+#    #+#             */
/*   Updated: 2025/05/21 18:10:27 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc == 2)
	{
		for(int i=0; argv[1][i]; ++i)
		{
			printf("%d", ft_isprint(argv[1][i]));
		}
		printf("\n");
	}
	else
		printf("Invalid input");
	return 0;
}*/
