/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:06:06 by thchau            #+#    #+#             */
/*   Updated: 2025/12/01 18:22:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
#include "get_next_line.h"

void print_lines_from_file(int fd) {
    char *line;
    int line_num = 1;

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", line_num++, line);
        free(line);
    }
    printf("End of file reached or NULL returned\n");
}

int main()
{
	int val = 50;
	int i =0;
	int tmp;
	int passw = 0;

	int fd;
	char *p;
	char fc;
    fd = open("p.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening p.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL) {
		fc = p[0];
		tmp = atoi(p + 1) % 100;
		if (fc == 'L')
		{
			if ((val - tmp) >= 0)
				val = val - tmp;
			else
				val = 100 - (tmp - val);
		}
		else if (fc == 'R')
		{
			if ((val + tmp) <= 99)
				val = val + tmp;
			else
				val = (tmp + val) - 100;
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