/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:25:51 by thchau            #+#    #+#             */
/*   Updated: 2025/09/08 12:31:11 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_input
{
	int target;
	int set_size;
	int *subset;
} t_input;

void	ft_print_subset(int *nums, int size)
{
	int i;
	
	if (!nums)
		return ;
	i = 0;
	while (i < size)
	{
		printf("%i ", nums[i]);
		i++;
	}
	printf("\n");
}

int ft_strlen(char *str)
{
	int i;
	
	if (!str)
		return 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void find_subsets(t_input *input, int *set, int subset_size, int index)
{
	if (input->target == 0)
	{
		ft_print_subset(input->subset, subset_size);
		return;
	}
	
	if (index >= input->set_size || input->target < 0)
		return ;
	
	input->subset[subset_size] = set[index];
	input->target -= set[index];
	find_subsets(input, set, subset_size + 1, index + 1);
	input->target += set[index];
	find_subsets(input, set, subset_size, index + 1);
}

int main (int argc, char **argv)
{
	int		i;
	t_input	input;
	int		*set;
	// int 	argc = 8;
	// char *argv[8] = {"test", "3", "1", "0", "2", "4", "5", "3"};
	
	if (argc < 2)
	{
		write(2, "Usage: ", 7);
		write(2, "./powerset ", 12);
		write(2, "<total> <number1> <number2> ...", 32);
		write(2, "\n", 1);
		return (1);
	}
	input.target = atoi(argv[1]);
	input.set_size = argc - 2;
	i = 0;
	set = malloc((argc - 2) * sizeof(int));
	if (set == NULL) {
        perror("malloc failed");
        return 1;
    }
	while (i < argc - 2)
	{
		set[i] = atoi(argv[i + 2]);
		i++;
	}
	input.subset = malloc(input.set_size * sizeof(int));
	if (input.subset == NULL) {
        perror("malloc failed");
        return 1;
    }
	find_subsets(&input, set, 0, 0);
	free(input.subset);
	free(set);
	return 0;
}