/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:29:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/24 10:10:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&table, argv) == ERROR_PARSE)
			return (EXIT_FAILURE);
		if (data_init(&table) == ERROR_INIT)
		{
			clean_up(&table);
			return (EXIT_FAILURE);
		}
		if (dinner_start(&table) == ERROR_DINNER_START)
		{
			clean_up(&table);
			return (EXIT_FAILURE);
		}
		clean_up(&table);
	}
	else
	{
		log_error("Wrong input.\nUsage: ./philo <philos>"
			" <time_to_die> <time_to_eat> <time_to_sleep> [num_of_meals]");
	}
	return (EXIT_SUCCESS);
}
