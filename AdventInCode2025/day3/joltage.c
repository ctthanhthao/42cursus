/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joltage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:05:08 by thchau            #+#    #+#             */
/*   Updated: 2025/12/03 09:35:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	int fd;
	char *p;
	int i , j;
	int digit;
	int max_pos;
	int max_val1;
	int max_val2;
	int result = 0;
	
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL)
	{
		i = 0;
		max_pos = 0;
		max_val1 = 0;
		max_val2 = 0;
		int len = ft_strlen(p) - 1;
		// find max value for 1st round
		while(p[i])
		{
			if ((p[i] - '0') > max_val1)
			{
				max_val1 = p[i] - '0';
				max_pos = i;
			}
			i++;
		}
		printf("max_pos = %i, len = %i\n", max_pos, len);
		if (max_pos == len - 1)
		{
			i = 0;
			max_val1 = 0;
			while(p[i])
			{
				if ((p[i] - '0') > max_val1)
				{
					max_val1 = p[i] - '0';
					max_pos = i;
				}
				i++;
				if (i == len - 1)
					break;
			}
		}
		char *p2 = p + max_pos + 1;
		j = 0;
		while(p2[j])
		{
			if ((p2[j] - '0') > max_val2)
			{
				max_val2 = p2[j] - '0';
			}
			j++;
		}
		printf("Turn on %i%i\n", max_val1, max_val2);
		result += (max_val1 * 10) + max_val2;
	}
	printf("Result is %i\n", result);
	return 0;
}