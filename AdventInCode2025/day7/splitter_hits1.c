/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:40:51 by thchau            #+#    #+#             */
/*   Updated: 2025/12/07 22:28:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd); // your function

int main(void)
{
    int fd = open("test1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char *line = get_next_line(fd);
    if (!line) return 1;

    int width = 0;
	int lineNum = 0;
    while (line[width] && line[width] != '\n')
        width++;

    long *curr = calloc(width, sizeof(long));
    long *next = calloc(width, sizeof(long));

    // find S
    for (int i = 0; i < width; i++) {
        if (line[i] == 'S') {
            curr[i] = 1;   // start with one timeline
            break;
        }
    }

    free(line);

    // process rows
    while ((line = get_next_line(fd)) != NULL) {
        for (int i = 0; i < width; i++) next[i] = 0;

        for (int col = 0; col < width; col++) {
            long cnt = curr[col];
            if (cnt == 0) continue;

            char c = line[col];

            if (c == '^') {
                // split left
                if (col - 1 >= 0)
                    next[col - 1] += cnt;

                // split right
                if (col + 1 < width)
                    next[col + 1] += cnt;
            }
            else {
                // continue straight
                next[col] += cnt;
            }
        }

        // swap buffers
        long *tmp = curr;
        curr = next;
        next = tmp;

        free(line);
    }

    // sum remaining timelines
    long result = 0;
    for (int i = 0; i < width; i++)
        result += curr[i];

    printf("Result = %ld\n", result);

    free(curr);
    free(next);
    close(fd);
    return 0;
}
