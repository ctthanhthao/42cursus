/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:35:47 by thchau            #+#    #+#             */
/*   Updated: 2025/09/05 12:14:39 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int ft_strlen(char *s)
{
	int l = 0;
	
	if (!s)
		return (0);
	while (s[l])
		l++;
	return l;
}

bool is_safe(int row, int col, int *result)
{
	int r;
	
	for (int c = 0; c < col; c++)
	{
		r = result[c];
		if (r == row)
			return (false);
		if (abs(r - row) == abs(c - col))
			return (false);
	}
	return (true);
}

void solve(int col, int n, int *results)
{
	if (col == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%i ", results[i]);
			if (i == n - 1)
				printf("\n");
		}	
		return;
	}
	for (int row = 0; row < n; row++)
	{
		if (is_safe(row, col, results))
		{
			results[col] = row;
			solve(col + 1, n, results);
		}
	}
}

int main (int argc, char **argv)
{
	int	n;
	int *results;
	int i;
	
	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " <number>", 9);
		write(2, "\n", 2);
		return (1);
	}
	n = atoi(argv[1]);
	if (n <= 0)
	{
		write (2, "The number should be larger than 0.", 36);
		return (1);
	}
	results = malloc(n * sizeof(int));
	if (!results)
		perror("malloc failed.");
	for (i = 0; i < n; i++)
		results[i] = -1;
	solve(0, n, results);	
	free(results);
	return (0);
}