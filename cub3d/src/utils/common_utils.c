/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:49:04 by thchau            #+#    #+#             */
/*   Updated: 2026/04/22 07:11:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * It trims spaces which start from the beginning of the string
 */
char	*ft_trim(const char *str)
{
	int	start;
	int	len;

	if (!str)
		return (NULL);
	start = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[start]))
		start++;
	return (ft_substr(str, start, len));
}

int	ft_arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/**
 * free_arr - Frees a dynamically allocated array of strings
 * @arr: Pointer to the array of strings to be freed
 *
 * Description:
 * This function deallocates memory for an array of strings by freeing each
 * individual string element and then the array itself. It should be called
 * when the array is no longer needed to prevent memory leaks.
 *
 * Return: void
 */
void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

bool	is_map_char(char c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| ft_isspace(c));
}
