/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_product2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/05 12:59:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned long long (*parse_ranges(int fd, int *numRange))[2] {
    char *p;
    int capacity = 16;
    unsigned long long (*ranges)[2] = malloc(capacity * sizeof(*ranges));
    if (!ranges) {
        perror("malloc");
        return NULL;
    }

    *numRange = 0;

    while ((p = get_next_line(fd)) != NULL) {
		if (p[0] == '\n' || isspace(p[0]))
		{
			free(p);
			break;
		}
        // grow array when needed
        if (*numRange == capacity) {
            capacity *= 2;
            unsigned long long (*new_grid)[2] = realloc(ranges, capacity * sizeof(*new_grid));
            if (!new_grid) {
                perror("realloc");
                free(ranges);
                free(p);
                return NULL;
            }
            ranges = new_grid;
        }

        char **tmp = ft_split(p, '-');
        if (!tmp || !tmp[0] || !tmp[1]) {
            fprintf(stderr, "Error splitting range: %s\n", p);
            free(p);
            if (tmp) free_split(tmp);
            free(ranges);
            return NULL;
        }

        ranges[*numRange][0] = (unsigned long long)ft_atoll(tmp[0]);
        ranges[*numRange][1] = (unsigned long long)ft_atoll(tmp[1]);
        (*numRange)++;

        free(p);
        free_split(tmp);
    }

    return ranges;
}

// Comparison function for qsort
int cmp(const void *a, const void *b) 
{
	const unsigned long long *r1 = a;
	const unsigned long long *r2 = b;

	if (r1[0] < r2[0]) return -1;
	if (r1[0] > r2[0]) return 1;
	return 0;
};

void	sort_ids_increasing(unsigned long long (*ranges)[2], int numRange)
{
	unsigned long long tmp;
	
	for (int i = 0; i < numRange; i++)
	{
		if (ranges[i][0] > ranges[i][1])
		{
			tmp = ranges[i][0];
			ranges[i][0] = ranges[i][1];
			ranges[i][1] = tmp;
		}
	}
}
	
void sort_arr_by_first_id(unsigned long long (*ranges)[2], int numRange)
{
	if (!ranges || numRange <= 1)
		return;
	qsort(ranges, numRange, sizeof(ranges[0]), cmp);
}

int main()
{
	int fd;
    char *p;
    int numRange = 0;
    unsigned long long result = 0;
    unsigned long long (*ranges)[2];
	unsigned long long start, end, prev_end, prev_start;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	ranges = parse_ranges(fd, &numRange);
    if (!ranges)
	{
		close(fd);
		perror("Error parsing ranges");
        return 1;
	}
		
    close(fd);
	sort_ids_increasing(ranges, numRange);
    sort_arr_by_first_id(ranges, numRange);
	prev_end = 0;
	for(int i = 0; i < numRange; i++)
	{
		start = ranges[i][0];
		end = ranges[i][1];
		printf("start = %llu - end = %llu \n", start, end);
		if (start <= prev_end)
			start = prev_end + 1;
		if (end >= start)
		{
			result += end - start + 1;
			prev_end = end;
		}
	}
    printf("Result is %llu with num of row is %i\n", result, numRange);
	free(ranges);
	return 0;
}