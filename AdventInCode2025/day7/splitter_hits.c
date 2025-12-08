/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_hits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/07 21:05:11 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	int fd;
    char *p;
    unsigned long long result = 0;
	int	hits, len, i = 0;
	char	*mask;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	// create mask line
	p = get_next_line(fd);
	mask = ft_strdup(p);
	if (!mask)
	{
		free(p);
		return 1;
	}
	len = ft_strlen(p);
	while (p[i])
	{
		if (p[i] == 'S')
			mask[i] = '|';
		else
			mask[i] = '.';
		i++;
	}
	while ((p = get_next_line(fd)) != NULL) {
		i = 0;
		while (p[i])
		{
			if (p[i] == '^' && mask[i] == '|')
			{
				mask[i] = '.';
				if (i - 1 >= 0)
					mask[i - 1] = '|';
				if (i + 1 < len)
					mask[i + 1] = '|';
				result++;	
			}
			i++;
		}
        free(p);
    }
    printf("Result is %llu \n", result);
	free(mask);
	return 0;
}