/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:11 by phofer            #+#    #+#             */
/*   Updated: 2025/05/21 15:55:22 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*

#include <stdio.h>

int main (int argc, char *argv[])
{
	if (argc == 2)
	{
		for(int i=0; argv[1][i]; ++i)
		{
			printf("%d", ft_isalpha(argv[1][i]));
		}
		printf("\n");
	}
	else
		printf("Invalid input");
	return 0;
}*/
