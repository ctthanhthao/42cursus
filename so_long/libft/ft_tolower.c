/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:20:13 by thchau            #+#    #+#             */
/*   Updated: 2024/09/19 15:53:30 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*#include <stdio.h>
int main() {
    char upper = 'B';
    char lower = 'b';
    char number = '7';

    printf("Original: %c, Lowercase: %c\n", upper, ft_tolower(upper));
    printf("Original: %c, Lowercase: %c\n", lower, ft_tolower(lower));
    printf("Original: %c, Lowercase: %c\n", number, ft_tolower(number));

    return 0;
}*/