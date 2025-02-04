/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:02:51 by thchau            #+#    #+#             */
/*   Updated: 2025/01/16 18:44:40 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_stack	*sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	size_t	j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ps_atoi(tmp[i]);
		if (j == PROCESS_ERROR)
		{
			ft_free_arr(tmp);
			ft_stack_free(&a);
			ft_error();
		}
		ft_stack_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_free_arr(tmp);
	return (a);
}

t_stack	*ft_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	size_t	j;

	i = 1;
	a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ps_atoi(argv[i]);
			if (j == PROCESS_ERROR)
			{
				ft_stack_free(&a);
				ft_error();
			}
			ft_stack_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
