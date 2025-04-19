/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:29:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/18 21:12:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "clean_up.c"
#include "dinner.c"
#include "getters_setters.c"
#include "init.c"
#include "log_msg_error.c"
#include "parsing.c"
#include "philo_actions.c"
#include "safe_functions.c"
#include "utils.c"

int main ()
{
	t_table	table;
	char *argv[5] = {"./philo", "1", "100", "100", "100"};
	int argc = sizeof(argv)/sizeof(argv[0]);
	if (argc == 5 || argc == 6)
	{
		//1. error checking, filling table
		if (parse_input(&table, argv) == ERROR_PARSE)
			return (EXIT_FAILURE);
		//2. creat thread, malloc 
		if (data_init(&table) == ERROR_INIT)
			return (EXIT_FAILURE);
		//3. philos start to get forks to eat
		dinner_start(&table);
		
		//4.
		clean_up(&table);
	}
	else
	{
		log_error("Wrong input. <Usage> ./philo <philos> <time_to_die>"
			" <time_to_eat> <time_to_sleep> <[num of meals]>");
	}
	return (EXIT_SUCCESS);
}