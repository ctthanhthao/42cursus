/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:42:45 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int main()
{
    // Characters are promoted to int when passed to the function
    printf("%c\n", ft_tolower('A')); // Outputs: A
    printf("%c\n", ft_tolower('b')); // Outputs: B
    printf("%c\n", ft_tolower('Z')); // Outputs: Z
    printf("%c\n", ft_tolower('1')); // Outputs: 1
    return 0;
}
*/
