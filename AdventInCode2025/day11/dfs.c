/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:32:00 by thchau            #+#    #+#             */
/*   Updated: 2025/12/12 09:28:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>


Node graph[MAX_NODES];
int node_count = 0;
long long memo[MAX_NODES];
int memo_used[MAX_NODES];

// -------- Node Lookup/Creation --------
int get_node_id(const char *name) {
    for (int i = 0; i < node_count; i++)
	{
        if (strcmp(graph[i].name, name) == 0)
            return i;
	}

    // create new node
	printf("creating node %d '%s'\n", node_count, name);
    strcpy(graph[node_count].name, name);
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
long long count_paths(int current, int target) {

    // If already computed, return cached value
    if (memo_used[current])
        return memo[current];

    // If this is the target, 1 path
    if (current == target) {
        memo_used[current] = 1;
        memo[current] = 1;
        return 1;
    }

    long long total = 0;

    // Sum all child paths
    for (int i = 0; i < graph[current].edge_count; i++) {
        int next = graph[current].edges[i];
        total += count_paths(next, target);
    }

    // Cache result
    memo_used[current] = 1;
    memo[current] = total;
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
    int start = get_node_id("you");
	int target = get_node_id("out");

	memset(memo_used, 0, sizeof(memo_used));

	long long result = count_paths(start, target);

	printf("Total paths: %lld\n", result);
    return 0;
}
