/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:53:32 by thchau            #+#    #+#             */
/*   Updated: 2024/10/31 13:17:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_strreverse(char *s)
{
	int		start;
	int		end;
	char	c;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (start < end)
	{
		c = s[start];
		s[start] = s[end - 1];
		s[end - 1] = c;
		start ++;
		end --;
	}
	return (s);
}
