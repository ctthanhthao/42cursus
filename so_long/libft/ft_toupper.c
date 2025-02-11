/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:08:06 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:53:36 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*#include <stdio.h>
int main() {
    char lower = 'a';
    char upper = 'A';
    char number = '5';

    printf("Original: %c, Uppercase: %c\n", lower, ft_toupper(lower));
    printf("Original: %c, Uppercase: %c\n", upper, ft_toupper(upper));
    printf("Original: %c, Uppercase: %c\n", number, ft_toupper(number));

    return 0;
}*/