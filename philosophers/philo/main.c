/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:29:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/17 10:23:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
	t_table	table;
	if (argc == 5 || argc == 6)
	{
		//1. error checking, filling table
		if (parse_input(&table, argv) == ERROR_PARSE)
			return (EXIT_FAILURE);
		//2. creat thread, malloc 
		printf("DONE parse_input\n");
		if (data_init(&table) == ERROR_INIT)
			return (EXIT_FAILURE);
		printf("DONE data_init\n");
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