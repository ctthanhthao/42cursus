/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_circuit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/09 19:13:15 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <math.h>

static double distance3D(unsigned int *p, unsigned int *q)
{
    double dx = (double)p[0] - q[0];
    double dy = (double)p[1] - q[1];
    double dz = (double)p[2] - q[2];
    return sqrt(dx*dx + dy*dy + dz*dz);
}

static t_edge	*calculate_conn(unsigned int (*boxes)[3], unsigned int numBox, unsigned int *conCount)
{
	unsigned int totalEdges = (numBox*(numBox - 1))/2;
	int i = 0, j = 0, connNum = 0;
	unsigned int *num1;
	unsigned int *num2;
	t_edge *edges = malloc(totalEdges * sizeof(t_edge));
	if (!edges)
	{
		perror("malloc edges failed");
		return NULL;
	}
	
	while (i < numBox)
	{
		num1 = boxes[i];
		j = i + 1;
		while (j < numBox)
		{
			num2 = boxes[j];
			edges[connNum].dist = distance3D(num1, num2);
			edges[connNum].i = i;
			edges[connNum].j = j;
			j++;
			connNum++;
		}
		i++;
	}
	*conCount = connNum;
	return (edges);
}

unsigned int (*parse_boxes(int fd, unsigned int *numRange))[3] {
    char *p;
    int capacity = 16;
    unsigned int (*boxes)[3] = malloc(capacity * sizeof(*boxes));
	
    if (!boxes) {
        perror("malloc");
        return NULL;
    }
    *numRange = 0;
    while ((p = get_next_line(fd)) != NULL) {
        // grow array when needed
        if (*numRange == capacity) {
            capacity *= 2;
            unsigned int (*new_grid)[3] = realloc(boxes, capacity * sizeof(*new_grid));
            if (!new_grid) {
                perror("realloc");
                free(boxes);
                free(p);
                return NULL;
            }
            boxes = new_grid;
        }
        char **tmp = ft_split(p, ',');
        if (!tmp || !tmp[0] || !tmp[1] || !tmp[2]) {
            fprintf(stderr, "Error parsing coordinators: %s\n", p);
            free(p);
            if (tmp) free_split(tmp);
            free(boxes);
            return NULL;
        }
		boxes[*numRange][0] = (unsigned int)atoi(tmp[0]);
		boxes[*numRange][1] = (unsigned int)atoi(tmp[1]);
		boxes[*numRange][2] = (unsigned int)atoi(tmp[2]);
        (*numRange)++;
        free(p);
        free_split(tmp);
    }

    return boxes;
}

static int compare_edge(const void *a, const void *b)
{
    const t_edge *c1 = (const t_edge *)a;
    const t_edge *c2 = (const t_edge *)b;

    if (c1->dist < c2->dist)
        return -1;
    if (c1->dist > c2->dist)
        return 1;
    return 0;
}

static void sort_conns(t_edge *conns, int numConn)
{
	if (!conns || numConn <= 1)
		return;
	qsort(conns, numConn, sizeof(t_edge), compare_edge);
}

int dsu_find(t_dsu *dsu, int x)
{
    if (dsu[x].parent != x)
        dsu[x].parent = dsu_find(dsu, dsu[x].parent);
    return dsu[x].parent;
}

int dsu_union(t_dsu *dsu, int a, int b)
{
    a = dsu_find(dsu, a);
    b = dsu_find(dsu, b);

    if (a == b)
        return 0;

    if (dsu[a].size < dsu[b].size) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    dsu[b].parent = a;
    dsu[a].size += dsu[b].size;
	return 1; /*union happened*/
}

int main()
{
	int fd;
    char *p;
	unsigned int (*boxes)[3];
	unsigned int	numBoxes, numEdges;
	t_edge *edges;
	
	
	int	hits, len, i = 0;
	char	*mask;
    
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test1.txt");
        return 1;
    }
	boxes = parse_boxes(fd, &numBoxes);
	edges = calculate_conn(boxes, numBoxes, &numEdges);
	sort_conns(edges, numEdges);
	// for (int i = 0; i < numEdges; i++)
	// {
	// 	printf("conn[%i] = [%.2f, %u[%i, %i,%i], %u[%i, %i, %i]]\n"
	// 		, i, edges[i].dist, edges[i].i
	// 		,boxes[edges[i].i][0], boxes[edges[i].i][1], boxes[edges[i].i][2],
	// 		edges[i].j
	// 		,boxes[edges[i].j][0], boxes[edges[i].j][1], boxes[edges[i].j][2]
	// 	);
	// }
	/*---- DSU --------*/
	t_dsu *dsu = malloc(numBoxes * sizeof(t_dsu));
	if (!dsu)
	{
		perror("Error alloc dsu");
		free(edges);
    	free(dsu);
	}
	for (int i = 0; i < numBoxes; i++)
	{
		dsu[i].parent = i;
		dsu[i].size = 1;
	}
	/* ---- Apply first K edges ---- */
	unsigned int accepted = 0;
	int K = numEdges;
	// if (K > numEdges)
	// 	K = numEdges;
	t_edge last_edge = {0.0, 0, 0};
	for (unsigned long i = 0; i < numEdges; i++) {
		/* Try to union the edge */
		if (dsu_union(dsu, edges[i].i, edges[i].j)) {
			/* this edge was accepted (merged two components) */
			accepted++;
			last_edge = edges[i];

			/* optional debug print of each accepted merge */
			// printf("ACCEPTED[%u]: dist=%.5f  %u[%u,%u,%u] <-> %u[%u,%u,%u]\n",
			// 	accepted,
			// 	last_edge.dist,
			// 	last_edge.i,
			// 	boxes[last_edge.i][0], boxes[last_edge.i][1], boxes[last_edge.i][2],
			// 	last_edge.j,
			// 	boxes[last_edge.j][0], boxes[last_edge.j][1], boxes[last_edge.j][2]
			// );

			// if (accepted == (int)numBoxes - 1) {
			// 	/* we've connected every box into one component */
			// 	break;
			// }
		}
   	 }
	/* ---- Compute sizes of circuits ---- */

    if (accepted != numBoxes - 1) {
        fprintf(stderr, "Warning: only %u accepted unions (expected %u).\n", accepted, numBoxes - 1);
    }

    /* last_edge now holds the final accepted edge (the last union performed) */
    printf("\nLast accepted edge: dist=%.5f  %u[%u,%u,%u] <-> %u[%u,%u,%u]\n",
        last_edge.dist,
        last_edge.i,
        boxes[last_edge.i][0], boxes[last_edge.i][1], boxes[last_edge.i][2],
        last_edge.j,
        boxes[last_edge.j][0], boxes[last_edge.j][1], boxes[last_edge.j][2]
    );

    unsigned long long xprod = (unsigned long long)boxes[last_edge.i][0] * (unsigned long long)boxes[last_edge.j][0];
    printf("Product of X coords = %llu\n", xprod);

    /* optional: compute and print final sizes like you did */
    int *finalSizes = calloc(numBoxes, sizeof(int));
    for (unsigned int i = 0; i < numBoxes; i++) {
        int root = dsu_find(dsu, i);
        finalSizes[root] += 1;
    }
    
	/* ---- Extract all non-zero sizes ---- */

    int sizes[1000]; // numBoxes
    int count = 0;

    for (int i = 0; i < 1000; i++) {
        if (finalSizes[i] > 0)
            sizes[count++] = finalSizes[i];
    }

	/* ---- Sort sizes descending ---- */

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sizes[j] > sizes[i]) {
                int tmp = sizes[i];
                sizes[i] = sizes[j];
                sizes[j] = tmp;
            }
        }
    }

    /* ---- Multiply largest 3 ---- */

    unsigned long long result = 1;
    for (int i = 0; i < 3 && i < count; i++)
        result *= sizes[i];

    printf("Largest circuit sizes: %d, %d, %d\n",
           sizes[0], sizes[1], sizes[2]);
    printf("Result = %llu\n", result);
		
	free(finalSizes);
    free(edges);
    free(dsu);
    free(boxes);
    close(fd);
    return 0;
}