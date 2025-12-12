#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define MAX_X 100000   // adjust to maximum coordinate +1
#define MAX_Y 100000

char grid[MAX_Y][MAX_X]; // 0 = empty, 1 = red, 2 = green

typedef struct {
    unsigned int x, y;
} Point;

void fill_grid(Point *reds, int n) {
    for (int i = 0; i < n; i++) {
        unsigned int x1 = reds[i].x;
        unsigned int y1 = reds[i].y;
        unsigned int x2 = reds[(i+1)%n].x;
        unsigned int y2 = reds[(i+1)%n].y;

        // mark red tile
        grid[y1][x1] = 1;

        // mark green tiles connecting consecutive red tiles
        if (x1 == x2) { // vertical line
            for (unsigned int y = y1 < y2 ? y1 : y2; y <= (y1 > y2 ? y1 : y2); y++)
                if (grid[y][x1] == 0) grid[y][x1] = 2;
        } else { // horizontal line
            for (unsigned int x = x1 < x2 ? x1 : x2; x <= (x1 > x2 ? x1 : x2); x++)
                if (grid[y1][x] == 0) grid[y1][x] = 2;
        }
    }
}

int is_valid_rectangle(Point a, Point b) {
    unsigned int x1 = a.x < b.x ? a.x : b.x;
    unsigned int x2 = a.x > b.x ? a.x : b.x;
    unsigned int y1 = a.y < b.y ? a.y : b.y;
    unsigned int y2 = a.y > b.y ? a.y : b.y;

    for (unsigned int y = y1; y <= y2; y++)
        for (unsigned int x = x1; x <= x2; x++)
            if (grid[y][x] == 0) // empty tile inside rectangle
                return 0;
    return 1;
}

unsigned long long largest_rectangle(Point *reds, int n) {
    unsigned long long max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (is_valid_rectangle(reds[i], reds[j])) {
                unsigned long long area = 
                    (unsigned long long)(abs((int)reds[i].x - (int)reds[j].x) + 1) *
                    (unsigned long long)(abs((int)reds[i].y - (int)reds[j].y) + 1);
                if (area > max_area)
                    max_area = area;
            }
        }
    }
    return max_area;
}

Point *parse_points(int fd, unsigned int *row)
{
    char *p;
    int capacity = 500;
    Point *points = malloc(capacity * sizeof(grid));
	
    if (!points) {
        perror("malloc points");
        return NULL;
    }
    *row = 0;
    while ((p = get_next_line(fd)) != NULL) {
        // grow array when needed
        char **tmp = ft_split(p, ',');
        if (!tmp || !tmp[0] || !tmp[1]) {
            fprintf(stderr, "Error parsing grid: %s\n", p);
            free(p);
            if (tmp) free_split(tmp);
            free(points);
            return NULL;
        }
		points[*row].y = (unsigned int)atoi(tmp[0]); // y
		points[*row].x = (unsigned int)atoi(tmp[1]); // x
        (*row)++;
        free(p);
        free_split(tmp);
    }

    return points;
}

int main() {
    // Example: 8 red points
    int fd;
    char *p;
	char	*mask;
	Point *points;
	char 	**matrix;
	unsigned int	lenPoints = 0;
    
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	points = parse_points(fd, &lenPoints);
	close(fd);
    // Clear grid
    for (int y=0; y<MAX_Y; y++)
        for (int x=0; x<MAX_X; x++)
            grid[y][x] = 0;

    // Fill grid with red and green tiles
    fill_grid(points, lenPoints);

    // Compute largest valid rectangle
    unsigned long long max_area = largest_rectangle(points, lenPoints);

    printf("Largest rectangle area = %llu\n", max_area);
    return 0;
}