/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcz <amarcz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:42:37 by amarcz            #+#    #+#             */
/*   Updated: 2024/09/24 18:44:54 by amarcz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
		{
			temp = (char *)(s + i);
		}
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)(s + i));
	return (temp);
}
/*
int main (void)
{
    char txt[] = "Hello";
    char *c;

    printf("Original text: %s\n", txt);
    c = ft_strrchr(txt, 'l');
    if(c)
    {
        printf("Found text: %s\n", c);
    }
    else
    {
        printf("Text not found!\n");
    }

    c = ft_strrchr(txt, 'z');
    if(c)
    {
        printf("Found text: %s\n", c);
    }
    else
    {
        printf("Text not found!\n");
    }
}
*/
