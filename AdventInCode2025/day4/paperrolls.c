/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paperrolls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/04 12:06:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int is_accessed(char **grid, int row, int col, int max_row, int max_col)
{
	int num_of_rolls = 0;
	if (grid[row][col] == '@')
	{
		if (col - 1 >= 0 && grid[row][col - 1] == '@')
			num_of_rolls++;
		if (col + 1 <= max_col && grid[row][col + 1] == '@')
			num_of_rolls++;
		if (row - 1 >= 0 && grid[row - 1][col] == '@')
			num_of_rolls++;
		if (row + 1 < max_row && grid[row + 1][col] == '@')
			num_of_rolls++;
		if (row - 1 >= 0 && col - 1 >= 0 && grid[row - 1][col - 1] == '@')
			num_of_rolls++;
		if (row + 1 < max_row && col + 1 < max_col && grid[row + 1][col + 1] == '@')
			num_of_rolls++;
		if (row - 1 >= 0 && col + 1 < max_col && grid[row - 1][col + 1] == '@')
			num_of_rolls++;
		if (row + 1 < max_row && col - 1 >= 0 && grid[row + 1][col - 1] == '@')
			num_of_rolls++;
		if (num_of_rolls < 4)
			return 1;
		return 0; 
	}
	return 0;
}

int main()
{
	int fd;
    char *p;
    int rows = 0;
    int result = 0;
    int capacity = 16;
	int max_row = 0;
    char **grid = malloc(capacity * sizeof(char *));
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }

    while ((p = get_next_line(fd)) != NULL)
    {
        // grow array when needed
        if (rows == capacity)
        {
            capacity *= 2;
            char **new_grid = realloc(grid, capacity * sizeof(char*));
            if (!new_grid) {
                perror("realloc");
                return 1;
            }
            grid = new_grid;
        }

        grid[rows++] = ft_strdup(p);
		max_row++;
        free(p);
    }

    close(fd);

    // NULL terminate the array so while(grid[x]) is safe
    grid[rows] = NULL;

    int x = 0, y = 0;
	int max_col = ft_strlen(grid[x]);
    while (grid[x])
    {
        y = 0;
        while (grid[x][y])
        {
            if (is_accessed(grid, x, y, max_row, max_col))
                result++;
            y++;
        }
        x++;
    }

    printf("Result is %i\n", result);
    free_split(grid);
    return 0;
}