/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:01:29 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 12:18:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	l1;
	unsigned int	l2;
	char			*result;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = (char *)malloc(l1 + l2 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, l1);
	ft_memcpy(result + l1, s2, l2 + 1);
	return (result);
}
