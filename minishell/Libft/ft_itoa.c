/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:41:01 by amarcz            #+#    #+#             */
/*   Updated: 2025/06/07 20:44:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

static void	fill_str(char *str, unsigned int nb, unsigned int index)
{
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + '0');
}

char	*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	size;

	if (nbr == 0)
		return (ft_strdup("0"));
	nb = (unsigned int)(nbr);
	if (nbr < 0)
		nb = (unsigned int)(nbr * -1);
	size = (unsigned int)(get_nb_size(nb) + (nbr < 0));
	str = ((char *)malloc(sizeof(char) * (size + 1)));
	if (!str)
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	fill_str (str, nb, size - 1);
	str[size] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main (void)
{
    char *s1 = ft_itoa(-623);
    printf("Result 1 is: %s\n", s1);
    //free(s1);
    char *s2 = ft_itoa(156);
    printf("Result 1 is: %s\n", s2);
    free(s2);
    char *s3 = ft_itoa(-0);   
    printf("Result 1 is %s\n", s3);
    char *s4 = ft_itoa(0);   
    printf("Result 1 is %s\n", s4);
    return (0);
}
*/
