/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:02:59 by thchau            #+#    #+#             */
/*   Updated: 2025/04/28 08:06:06 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

char	*ft_strdup(const char *src)
{
	size_t	s_len;
	size_t	idx;
	char	*ptr;

	s_len = ft_strlen(src);
	ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx <= s_len)
	{
		ptr[idx] = src[idx];
		idx++;
	}
	return (ptr);
}