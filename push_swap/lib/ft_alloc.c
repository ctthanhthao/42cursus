/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:09:40 by thchau            #+#    #+#             */
/*   Updated: 2025/01/13 14:08:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**ft_alloc(unsigned int n)
{
	char	**result;

	result = (char **) malloc((n + 1) * sizeof(char *));
	result[n] = NULL;
	while (n > 0)
	{
		result[--n] = NULL;
	}
	return (result);
}
