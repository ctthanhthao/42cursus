/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:32:00 by thchau            #+#    #+#             */
/*   Updated: 2025/12/12 09:27:40 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>


Node graph[MAX_NODES];
long long memo[MAX_NODES][4];
int memo_used[MAX_NODES][4];
int node_count = 0;

// -------- Node Lookup/Creation --------
int get_node_id(const char *name) {
    for (int i = 0; i < node_count; i++)
	{
        if (strcmp(graph[i].name, name) == 0)
            return i;
	}
    // create new node
    strcpy(graph[node_count].name, name);
//	printf("graph[%i].name = %s and name = %s\n", node_count, graph[node_count].name, name);
    graph[node_count].edge_count = 0;
    return node_count++;
}

// -------- Add Edge --------
void add_edge(const char *src, const char *dst) {
    int s = get_node_id(src);
    int d = get_node_id(dst);
    graph[s].edges[graph[s].edge_count++] = d;
}

void rtrim(char *s) {
    int len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r' || s[len-1] == ' ' || s[len-1] == '\t')) {
        s[len-1] = '\0';
        len--;
    }
}

// Memoized DFS: fast path-counting without enumerating
long long count_paths(int current, int target, int dac_id, int fft_id, int mask) {

    // Update mask when entering this node
    if (current == dac_id) mask |= 1;   // bit0
    if (current == fft_id) mask |= 2;   // bit1

    // If already computed for (node,mask) state — return cached
    if (memo_used[current][mask])
        return memo[current][mask];

    // Reached target
    if (current == target) {
        if (mask == 3) {   // visited both
            memo_used[current][mask] = 1;
            memo[current][mask] = 1;
            return 1;
        } else {
            return 0;
        }
    }

    long long total = 0;

    for (int i = 0; i < graph[current].edge_count; i++) {
        int next = graph[current].edges[i];
        total += count_paths(next, target, dac_id, fft_id, mask);
    }

    memo_used[current][mask] = 1;
    memo[current][mask] = total;
    return total;
}

// -------- Main --------
int main() {
	int fd;
    char *p, *left, *right;
	char ** sides;
	
	unsigned int (*boxes)[3];
    
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test1.txt");
        return 1;
    }
	while((p = get_next_line(fd)) != NULL)
	{
		rtrim(p);
		sides = ft_split(p, ':');
		if (!sides)
		{
			perror("Error sides");
			free(p);
			return 1;
		}
		left = sides[0];
		right = sides[1];
		char *token = strtok(right, " ");
		while (token != NULL) {
			add_edge(left, token);
			token = strtok(NULL, " ");
		}
		free(p);
		free_split(sides);
	}
    int start = get_node_id("svr");
    int target = get_node_id("out");
	int dac_id = get_node_id("dac");
	int fft_id = get_node_id("fft");
	printf("start = %i - target = %i - dac_id = %i - fft_id = %i\n",start, target, dac_id, fft_id);
    memset(memo_used, 0, sizeof(memo_used));

	memset(memo_used, 0, sizeof(memo_used));

	long long result = count_paths(start, target, dac_id, fft_id, 0);

	printf("Paths with dac+fft: %lld\n", result);
    return 0;
}
