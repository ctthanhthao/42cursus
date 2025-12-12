/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_rectangle1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/12 11:40:23 by thchau           ###   ########.fr       */
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
		grid[*row][0] = (unsigned int)atoi(tmp[0]); // y
		grid[*row][1] = (unsigned int)atoi(tmp[1]); // x
        (*row)++;
        free(p);
        free_split(tmp);
    }

    return grid;
}

static unsigned int find_max_dx(unsigned int (*grid)[2], unsigned int size)
{
	unsigned int max_dx = 0;
	for (int i = 0; i < size; i++)
	{
		if (grid[i][1] > max_dx)
			max_dx = grid[i][1];
	}
	return max_dx;
}

static unsigned int find_max_dy(unsigned int (*grid)[2], unsigned int size)
{
	unsigned int max_dy = 0;
	for (int i = 0; i < size; i++)
	{
		if (grid[i][0] > max_dy)
			max_dy = grid[i][0];
	}
	return max_dy;
}

static void fill_X_into_matrix(char ***mx, int col, int row)
{
	if ((*mx)[row][col] == '.')
		(*mx)[row][col] = 'X';
}

static void fill_sharp_and_X_into_matrix(unsigned int (*grid)[2], 
		unsigned int gridLen, unsigned int (*ranges_x)[2], unsigned int (*ranges_y)[2])
{
	unsigned int x1;
	unsigned int y1;
	unsigned int x2;
	unsigned int y2;
	unsigned int tmp;
	for (int i = 0; i < gridLen; i++)
	{
		x1 = grid[i][1];
		y1 = grid[i][0];
		for (int j = i + 1; j < gridLen; j++)
		{
			x2 = grid[j][1];
			y2 = grid[j][0];
			// coordinators have the same col
			//printf("[%u - %u] - [%u, %u]\n", y1, x1, y2, x2);
			if (y1 == y2)
			{
				if (x1 > x2)
				{//swap
					tmp = x2;
					x2 = x1;
					x1 = tmp;
				}
				if (ranges_y[y1][0] == 0)
				{
					ranges_y[y1][0] = x1;
					if (ranges_y[y1][1] < x2)
						ranges_y[y1][1] = x2;
				}
				else
				{
					if (ranges_y[y1][0] > x1)
						ranges_y[y1][0] = x1;
					if (ranges_y[y1][1] < x2)
						ranges_y[y1][1] = x2;	
				}
				// update ranges_x accordingly
				for (int k = x1 ;k <= x2; k++)
				{
					if (ranges_x[k][1] < y1)
					{
						if(ranges_x[k][0] == 0)
							ranges_x[k][0] = ranges_x[k][1];
						ranges_x[k][1] = y1;
					}
					else
					{
						if (ranges_x[k][0] == 0 || ranges_x[k][0] > y1)
							ranges_x[k][0] = y1;
					}
					//printf("update ranges_x[%i]: %i - %i\n",k, ranges_x[k][0], ranges_x[k][1]);
				}
			}
			else if (x1 == x2) //coordinators have the same row
			{
				if (y1 > y2)
				{//swap
					tmp = y2;
					y2 = y1;
					y1 = tmp;
				}
				if (ranges_x[x1][0] == 0)
				{
					ranges_x[x1][0] = y1;
					if (ranges_x[x1][1] < y2)
						ranges_x[x1][1] = y2;
				}
				else
				{
					if (ranges_x[x1][0] > y1)
						ranges_x[x1][0] = y1;
					if (ranges_x[x1][1] < y2)
						ranges_x[x1][1] = y2;	
				}
				// update ranges_y accordingly
				for (int k = y1; k <= y2; k++)
				{
					if (ranges_y[k][1] < x1)
					{
						if(ranges_y[k][0] == 0)
							ranges_y[k][0] = ranges_y[k][1];
						ranges_y[k][1] = x1;
					}
					else
					{
						if(ranges_y[k][0] == 0 || ranges_y[k][0] > x1)
							ranges_y[k][0] = x1;
					}
					//printf("update ranges_y[%i]: %i - %i\n",k, ranges_y[k][0], ranges_y[k][1]);
				}
			}
		}
	}
}

static void paint_inside(char ***mx, unsigned int (*ranges)[2])
{
	int i = 0, j = 0;
	int	start = 0;
	int	end = 0;
	
	while ((*mx)[i])
	{
		j = 0;
		start = -1;
		end = -1;
		while ((*mx)[i][j])
		{
			if ((*mx)[i][j] == '#' || (*mx)[i][j] == 'X')
			{
				if (start == -1)
					start = j;
				else
					end = j;
			}
			j++;
		}
		ranges[i][0] = start;
		ranges[i][1] = end; 
		i++; 
	}
}

void build_matrix(unsigned int dy, unsigned int dx, unsigned int (*grid)[2],
	 unsigned int gridLen, unsigned int (*ranges_x)[2], unsigned int (*ranges_y)[2])
{
	fill_sharp_and_X_into_matrix(grid, gridLen, ranges_x, ranges_y);
}

static int check_connected(unsigned int (*ranges_x)[2], unsigned int (*ranges_y)[2], unsigned int x1,
	unsigned int x2, unsigned int y1, unsigned int y2)
{
	// check [y1, x1] [y2, x2] [y1, x2] [y2, x1]
	if (ranges_x[x1][0] > 0 && ranges_x[x2][0] && ranges_y[y1][0] > 0 && ranges_y[y2][0] > 0
		&& y1 >= ranges_x[x1][0] && y1 <= ranges_x[x1][1]
		&& y2 >= ranges_x[x2][0] && y2 <= ranges_x[x2][1]
		&& x1 >= ranges_y[y1][0] && x1 <= ranges_y[y1][1]
		&& x2 >= ranges_y[y2][0] && x2 <= ranges_y[y2][1]
		&& y1 >= ranges_x[x2][0] && y1 <= ranges_x[x2][1]
		&& y2 >= ranges_x[x1][0] && y2 <= ranges_x[x1][1]
		&& x1 >= ranges_y[y2][0] && x1 <= ranges_y[y2][1]
		&& x2 >= ranges_y[y1][0] && x2 <= ranges_y[y1][1]
	)
	{
		printf("[y1,x1] = [%u, %u] --- [y2,x2] = [%u, %u]\n", y1, x1, y2, x2);
		printf("----- ranges -------\n");
		printf("ranges_x[%u]: %u - %u\n", x1, ranges_x[x1][0], ranges_x[x1][1]);
		printf("ranges_x[%u]: %u - %u\n", x2, ranges_x[x2][0], ranges_x[x2][1]);
		printf("ranges_y[%u]: %u - %u\n", y1, ranges_y[y1][0], ranges_y[y1][1]);
		printf("ranges_y[%u]: %u - %u\n\n", y2, ranges_y[y2][0], ranges_y[y2][1]);
		return 1;
	}
	return 0;
}

int main()
{
	int fd;
    char *p;
	char	*mask;
	unsigned int (*grid)[2];
	unsigned int (*ranges_x)[2]; // each element contains start y1 and end y2 in the same row
	unsigned int (*ranges_y)[2]; 
	unsigned int	gridLen = 0;
    
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	grid = parse_grid(fd, &gridLen);
	close(fd);
	unsigned int w = find_max_dx(grid, gridLen);
	unsigned int h = find_max_dy(grid, gridLen);
	ranges_x = malloc((w + 1) * sizeof(* ranges_x));
	ranges_y = malloc((h + 1) * sizeof(* ranges_x));
	if (!ranges_x || !ranges_y)
	{
		perror("Error malloc ranges");
		return 1;
	}
	for (int i = 0; i <= w; i++)
	{
		ranges_x[i][0] = 0;
		ranges_x[i][1] = 0;
	}
	for (int i = 0; i <= h; i++)
	{
		ranges_y[i][0] = 0;
		ranges_y[i][1] = 0;
	}
	build_matrix(h, w, grid, gridLen, ranges_x, ranges_y);
	// printf("/----   Print ranges. with h = %u, w = %u ----/\n", h, w);
	// for (int i = 0; i <= w; i++)
	// {
	// 	printf("ranges_x[%i]: %u - %u\n", i, ranges_x[i][0], ranges_x[i][1]);
	// }
	// printf("\n");
	// for (int i = 0; i <= h; i++)
	// {
	// 	printf("ranges_y[%i]: %u - %u\n", i, ranges_y[i][0], ranges_y[i][1]);
	// }
	// printf("dx = %u and dy = %u\n", h, w);
	// printf("/----   Print matrix. with h = %u, w = %u ----/\n", h, w);
	// for (int i = 0; i <= w; i++)
	// {
	// 	for (int j = 0; j <=h ; j++)
	// 	{
	// 		printf("%c", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	unsigned long long max = 0;
	unsigned long long subTotal;
	unsigned int x1, x2, y1, y2;
	for (int i = 0; i < gridLen; i++)
	{
		x1 = grid[i][1];
		y1 = grid[i][0];
		for (int j = i + 1; j < gridLen; j++)
		{
			x2 = grid[j][1];
			y2 = grid[j][0];
			unsigned long long dy = (unsigned long long)uabsdiff(y1, y2) + 1;
			unsigned long long dx = (unsigned long long)uabsdiff(x1, x2) + 1;
				//printf("[%u, %u] - [%u, %u] \n", grid[i][0], grid[i][1], grid[j][0], grid[j][1]);
			subTotal = dx * dy;
			if (subTotal > max && check_connected(ranges_x, ranges_y, x1, x2, y1, y2))
			{
				//printf("dy = %llu - dx = %llu - subTotal = %llu\n",dy, dx, subTotal);
					max = subTotal;	
			}
		}
	}
   	printf("Result is %llu \n", max);
	free(grid);
	free(ranges_x);
	return 0;
}
