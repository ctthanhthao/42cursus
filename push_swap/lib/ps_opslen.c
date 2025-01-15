/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:33:10 by thchau            #+#    #+#             */
/*   Updated: 2025/01/15 11:31:25 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_arrlen(char **ops)
{
	int	i;

	i = 0;
	if (!ops || !*ops)
		return (0);
	while (ops[i])
		i++;
	return (i);
}

int	ps_opslen_by_comma(char *ops)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (!ops)
		return (i);
	while (ops[i])
	{
		if (ops[i] == ',')
			count++;
		i++;
	}
	return (count);
}
