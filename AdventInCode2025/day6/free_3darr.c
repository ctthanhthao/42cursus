/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_3darr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:26:48 by thchau            #+#    #+#             */
/*   Updated: 2025/12/06 07:47:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char **arr)
{
	int i;

    if (!arr)
        return;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void	free_3darr(char ***arr)
{
	int i;

    if (!arr)
        return;
    i = 0;
    while (arr[i])
    {
        free_split(arr[i]);
        i++;
    }
    free(arr);
}