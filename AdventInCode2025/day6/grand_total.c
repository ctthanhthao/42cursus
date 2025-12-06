/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/06 22:23:18 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char **build_arr_contain_item(char *p, unsigned int *arr_len)
{
	unsigned int	i = 0, j = 0, count = 0;
	unsigned int	size;
	unsigned int	capacity = 16;
	char **arr = malloc(capacity * sizeof(char *));
	
	*arr_len = 0;
	while(p[i])
	{
		if (ft_isalnum(p[i]) || p[i] == '*' || p[i] == '+')
		{
			j = i;
			while (ft_isalnum(p[j]) || p[j] == '*' || p[j] == '+')
				j++;
			size = j - i;
			if (count + 1 == capacity) 
			{
				capacity *= 2;
				char **new_arr = realloc(arr, capacity * sizeof(char *));
				if (!new_arr)
				{
					perror("realloc");
					free_split(arr);
					return NULL;
				}
				arr = new_arr;
        	}
			arr[count++] = ft_substr(p, i, size);
			i = j;
		}
		else
			i++;
	}
	arr[count] = NULL;
	*arr_len = count;
	return arr;
}

void solve(char ***problem, unsigned int lastPos, unsigned int lenArr)
{
	unsigned long long	result = 0;
	char	op;
	int		h = 0, v = 0;
	unsigned long long	subResult;
	
	while (h < lenArr)
	{
		op = problem[lastPos][h][0];
		if (op == '*')
			subResult = 1;
		else
			subResult = 0;
		v = 0;
		while (v < lastPos)
		{
			if (op == '*')
				subResult *= atoi(problem[v][h]);
			else
				subResult += atoi(problem[v][h]);
			v++;
		}
		result += subResult;
		h++;
	}
	printf("Result is %llu\n", result);
}

int main()
{
	int				fd;
    char			*p;
	unsigned int	capacity = 4;
	unsigned int	count = 0, len = 0, len1 = 0;
	
    char ***problem = malloc(capacity * sizeof(char **));
	char **arr;
	
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test.txt");
        return 1;
    }
	while ((p = get_next_line(fd)) != NULL)
	{
		arr = build_arr_contain_item(p, &len);
		if (len1 == 0)
			len1 = len;
		if (!arr || len != len1)
		{
			if (arr)
				free_split(arr);
			perror("Error building array to contain items");
			free_3darr(problem);
			free(p);
			return 1;
		}
		if (count + 1 == capacity)
		{
			capacity *= 2;
			char ***new_arr = realloc(problem, capacity * sizeof(char **));
			if (!new_arr)
			{
				perror("realloc problem arr");
				free_3darr(problem);
				return 1;
			}
			problem = new_arr;
		}
		problem[count++] = arr;
		free(p);
	}
	problem[count] = NULL;
	close(fd);
	
	solve(problem, count - 1, len);
	
	free_3darr(problem);
	return 0;
}
