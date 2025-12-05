/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joltage2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 09:05:08 by thchau            #+#    #+#             */
/*   Updated: 2025/12/05 13:00:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	int fd;
	char *p;
	int i , j;
	int max_pos;
	int max_val1;
	unsigned long long val_in_one_row = 0;
	unsigned long long result = 0;
	int num_of_digit = 0;
	
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL)
	{
		i = 0;
		max_pos = -1;
		max_val1 = 0;
		val_in_one_row = 0;
		int len = ft_strlen(p) - 1;
		num_of_digit = 0;
		// find max value for 1st round
		while (num_of_digit < 12)
		{
			i = max_pos + 1;
			max_val1 = 0;
			while(p[i] && i <= len - 12 + num_of_digit)
			{
				if ((p[i] - '0') > max_val1)
				{
					max_val1 = p[i] - '0';
					max_pos = i;
				}
				i++;
			}
			num_of_digit++;
			val_in_one_row = (val_in_one_row * 10) + max_val1;
		}
		printf("Turn on : %llu\n", val_in_one_row);
		result += val_in_one_row;
	}
	printf("Result is %llu\n", result);
	return 0;
}