/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:42:48 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/25 10:44:48 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int main (void)
{
    printf("%c\n", ft_toupper('a')); 
    printf("%c\n", ft_toupper('B')); 
    printf("%c\n", ft_toupper('z'));
    printf("%c\n", ft_toupper('1'));
}
*/
