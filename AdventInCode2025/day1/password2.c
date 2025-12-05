/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:06:06 by thchau            #+#    #+#             */
/*   Updated: 2025/12/01 19:04:37 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
#include "get_next_line.h"

int main()
{
	int val = 50;
	int remainder;
	int passw = 0;
	int num;
	int fd;
	char *p;
	char fc;
	int i = 0;
	
    fd = open("p.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening p.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL) {
		fc = p[0];
		num = atoi(p + 1);
		remainder = num % 100;
		passw += num / 100;
		if (fc == 'L')
		{
			if ((val - remainder) >= 0)
				val = val - remainder;
			else
			{
				if (val != 0)
					passw++;
				val = 100 - (remainder - val);
			}
		}
		else if (fc == 'R')
		{
			if ((val + remainder) <= 99)
				val = val + remainder;
			else
			{
				val = (remainder + val) - 100;
				if (val != 0)
					passw++;
			}
		}	
		if (val == 0)
			passw++;
		i++;
        free(p);
    }
	printf("iteration : %i\n", i);
	printf("password is %i\n", passw);
	close(fd);
	return 0;
}