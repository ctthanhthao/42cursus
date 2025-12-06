/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grand_total1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:43 by thchau            #+#    #+#             */
/*   Updated: 2025/12/06 22:19:46 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char **get_one_number_block(char **arr, int idx, int len)
{
	char	**result;
	int		capacity = 10;
	int		count = 0;
	int		i = 0;

	if (!arr)
		return NULL;
	result = malloc(capacity * sizeof(char *));
	while (arr[i])
	{
		if (count + 1 == capacity)
		{
			capacity *= 2;
			char **new_arr = realloc(result, capacity * sizeof(char *));
			if (!new_arr)
			{
				perror("realloc");
				free_split(result);
				return NULL;
			}
			result = new_arr;
		}
		result[count++] = ft_substr(arr[i], idx, len);
		i++;
	}
	result[count] = NULL;
	return result;
}

char ***build_problem_arr(char **arr, unsigned int lenPro)
{
	int		i = 0, j = 0;
	char	*lastLine;
	int		countProb = 0;
	int		size = 0;
	unsigned int	capProb = 16;
	char **operators;
	char ***problem;

	lastLine = arr[lenPro];
	if (!lastLine)
		return NULL;
	problem = malloc(capProb * sizeof(char **));
	while(lastLine[i])
	{
		j = i + 1;
		while (lastLine[j] && lastLine[j] != '*' && lastLine[j] != '+')
			j++;
		size = j - i - 1;
		if (size == 0)
			break;
		operators = get_one_number_block(arr, i, size);
		if (!operators)
		{
			perror("Error getting one number block");
			free_3darr(problem);
			return NULL;
		}
		if (countProb + 1 == capProb)
		{
			capProb *= 2;
			char ***new_arr = realloc(problem, capProb * sizeof(char **));
			if (!new_arr)
			{
				perror("realloc problem arr");
				free_split(operators);
				free_3darr(problem);
				return NULL;
			}
			problem = new_arr;
		}
		problem[countProb++] = operators;
		i = j;
	}
	problem[countProb] = NULL;
	return problem;
}

void	solve(char ***problem, int lastPos)
{
	unsigned long long result = 0;
	unsigned long long subResult = 0;
	int		i = 0, j = 0, k = 0, len;
	char	op;
	int		num = 0;
	
	while(problem[i])
	{
		op = problem[i][lastPos][0];
		if (op == '+')
			subResult = 0;
		else
			subResult = 1;
		len = ft_strlen(problem[i][lastPos]);
		k = 0;
		while(k < len)
		{
			j = 0;
			num = 0;
			while (j < lastPos)
			{
				if (problem[i][j][k] != ' ')
					num = num * 10 + (problem[i][j][k] - '0');
				j++;
			}
			if (op == '+')
				subResult += num;
			else
				subResult *= num;
			k++;
		}
		result += subResult;
		i++;
	}
	printf("Result is %llu\n", result);
}

char **build_arr_contain_lines(int fd, unsigned int *numRow)
{
	char			*p;
	unsigned int	capacity = 4;
	unsigned int	count = 0;;
	char			**arr;

	arr = malloc(capacity * sizeof(char *));
	if (!arr)
	{
		perror("Error building array to contain lines");
		free(p);
		return NULL;
	}
	while ((p = get_next_line(fd)) != NULL)
	{
		if (count + 1 == capacity)
		{
			capacity *= 2;
			char **new_arr = realloc(arr, capacity * sizeof(char **));
			if (!new_arr)
			{
				perror("realloc problem arr");
				free_split(arr);
				return NULL;
			}
			arr = new_arr;
		}
		arr[count++] = ft_strdup(p);
		free(p);
	}
	arr[count] = NULL;
	*numRow = count;
	return (arr);
}

int main()
{
	int				fd;
    char			*p;
	unsigned int	numRow = 0;
	
    char ***problem;
	char **arr;
	
    fd = open("test1.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening test1.txt");
        return 1;
    }
	arr = build_arr_contain_lines(fd, &numRow);
	close(fd);
	if (!arr)
		return 1;
	problem = build_problem_arr(arr, numRow - 1);	
	if (!problem)
	{
		free_split(arr);
		return 1;
	}
	solve(problem, numRow - 1);
	free_split(arr);
	free_3darr(problem);
	return 0;
}
