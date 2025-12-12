/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_rectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/09 20:11:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline unsigned int uabsdiff(unsigned int a, unsigned int b) {
    return (a > b) ? (a - b) : (b - a);
}

unsigned int (*parse_grid(int fd, unsigned int *row))[2] {
    char *p;
    int capacity = 16;
    unsigned int (*grid)[2] = malloc(capacity * sizeof(*grid));
	
    if (!grid) {
        perror("malloc");
        return NULL;
    }
    *row = 0;
    while ((p = get_next_line(fd)) != NULL) {
        // grow array when needed
        if (*row == capacity) {
            capacity *= 2;
            unsigned int (*new_grid)[2] = realloc(grid, capacity * sizeof(*new_grid));
            if (!new_grid) {
                perror("realloc");
                free(grid);
                free(p);
                return NULL;
            }
            grid = new_grid;
        }
        char **tmp = ft_split(p, ',');
        if (!tmp || !tmp[0] || !tmp[1]) {
            fprintf(stderr, "Error parsing grid: %s\n", p);
            free(p);
            if (tmp) free_split(tmp);
            free(grid);
            return NULL;
        }
		grid[*row][0] = (unsigned int)atoi(tmp[0]);
		grid[*row][1] = (unsigned int)atoi(tmp[1]);
        (*row)++;
        free(p);
        free_split(tmp);
    }

    return grid;
}

int main()
{
	int fd;
    char *p;
	char	*mask;
	unsigned int (*grid)[2];
	unsigned int	gridLen = 0;
    
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	grid = parse_grid(fd, &gridLen);
	close(fd);
	unsigned long long max = 0;
	unsigned long long subTotal;
	for (int i = 0; i < gridLen; i++)
	{
		for (int j = i + 1; j < gridLen; j++)
		{
			unsigned long long dx = (unsigned long long)uabsdiff(grid[i][0], grid[j][0]) + 1;
			unsigned long long dy = (unsigned long long)uabsdiff(grid[i][1], grid[j][1]) + 1;
			subTotal = dx * dy;
			if (subTotal > max)
				max = subTotal;	
		}
	}
    printf("Result is %llu \n", max);
	free(grid);
	return 0;
}
