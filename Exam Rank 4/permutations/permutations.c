/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:43:39 by thchau            #+#    #+#             */
/*   Updated: 2025/09/08 11:43:47 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_print_subset(char *str)
{
	int i;
	
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	sort(char *str)
{
	int		i;
	int		j;
	char	tmp;
	
	if (!str)
		return;
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[j] < str[i])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	permute(char *str, int l, int r)
{
	int		i;
	char	tmp;
	
	if (l == r)
		ft_print_subset(str);
	else
	{
		i = l;
		while (i >= l && i <= r)
		{
			if (str[i] != str[l])
			{
				tmp = str[i];
				str[i] = str[l];
				str[l] = tmp;
			}
			permute(str, l + 1, r);
			if (str[i] != str[l])
			{
				tmp = str[i];
				str[i] = str[l];
				str[l] = tmp;
			}
			i++;
		}	
	}
}

int main (int argc, char **argv)
{
	char	*str;
	int		len;
	
	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, "./permutations ", 16);
		write(2, "<string>", 9);
		write(2, "\n", 1);
		return (1);
	}
	str = strdup(argv[1]);
	len = 0;
	while (str[len])
		len++;
	sort(str);
	permute(str, 0, len - 1);
	free(str);
	return (0);
}