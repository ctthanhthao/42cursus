/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:31:49 by thchau            #+#    #+#             */
/*   Updated: 2024/09/21 13:49:32 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>
void ft_replace_by_idx(unsigned int i, char *c)
{
	*c = i + '0';
}
int main()
{
	char s[] = "Hello World\0";
	ft_striteri(s, ft_replace_by_idx);
	printf("The modified string is %s\n", s);
	return 0;
}*/