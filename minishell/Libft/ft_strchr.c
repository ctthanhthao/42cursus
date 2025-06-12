/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:42:04 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 12:42:53 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*
int main (void)
{
    char txt[] = "Hello!";
    char *res;
    printf("Original string: %s\n", txt);

    res = ft_strchr(txt, 'l');
    if (res)
    {
        printf("New string: %s\n", res);
    }
    else
    {
        printf("Character not found. :( \n");
    }
    
    res = ft_strchr(txt, 'z');
    if (res)
    {
        printf("First occurrence of 'z': %s\n", res);
    }
    else
    {
        printf("Character not found.\n");
    }

    return (0);
}
*/
