/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/05 10:04:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int parse_ranges_and_ids(int fd, char ***ranges, char ***invIds)
{
	char *p;
	int numRanges = 0;
	int numIds = 0;
    int rangesCapacity = 16; // initial capacity of caller
    int idsCapacity = 16;
	int isItemId = 0;
	
	// build 2 arrays to contain Id range and inventory ID
    while ((p = get_next_line(fd)) != NULL)
    {
		if (p[0] == '\n' || isspace(p[0]))
			isItemId = 1;
		else
		{
			if (!isItemId)
			{
				if (numRanges == rangesCapacity)
				{
					rangesCapacity *= 2;
					char **new_grid = realloc(*ranges, rangesCapacity * sizeof(char*));
					if (!new_grid) {
						perror("realloc");
						return -1;
					}
					*ranges = new_grid;
				}
				(*ranges)[numRanges++] = ft_strdup(p);
			}
			else
			{
				if (numIds == idsCapacity)
				{
					idsCapacity *= 2;
					char **new_grid = realloc(*invIds, idsCapacity * sizeof(char*));
					if (!new_grid) {
						perror("realloc");
						return -1;
					}
					*invIds = new_grid;
				}
				(*invIds)[numIds++] = ft_strdup(p);
			}
		}
        free(p);
    }
	// NULL terminate the array so while(grid[x]) is safe
    (*ranges)[numRanges] = NULL;
	(*invIds)[numIds] = NULL;
	return 1;
}

int main()
{
	int fd;
    char *p;
    int result = 0;
	int capacity = 16;
	char **ranges = malloc(capacity * sizeof(char *));
	char **invIds = malloc(capacity * sizeof(char *));
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	// build 2 arrays to contain Id range and inventory ID
    if (parse_ranges_and_ids(fd, &ranges, &invIds) == -1)
	{
		perror("Error parsing ranges and ids");
		free_split(ranges);
		free_split(invIds);
		close(fd);
		return 1;
	}
    close(fd);

	int x = 0, y = 0;
	unsigned long long	id, start, end;
	char **range;
    while (invIds[x])
    {
        y = 0;
		id = ft_atoll(invIds[x]);
        while (ranges[y])
        {
			range = ft_split(ranges[y], '-');
			start = atoll(range[0]);
			end = atoll(range[1]);
			if (id >= start && id <= end)
			{
				result++;
				break;
			}
            y++;
        }
        x++;
    }

    printf("Result is %i\n", result);
    free_split(ranges);
    return 0;
}