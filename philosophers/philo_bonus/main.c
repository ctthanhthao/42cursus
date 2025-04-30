/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:29:56 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 09:24:33 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers_bonus.h"

void handle_sigchld(int sig) {
    (void)sig;  // unused parameter

    int status;
    pid_t pid;

    // Loop to reap all dead children
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFEXITED(status)) {
            printf("SIGCHLD: Child %d exited with status %d\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("SIGCHLD: Child %d was killed by signal %d\n", pid, WTERMSIG(status));
        }
    }
}

int	main(int argc, char **argv)
{
	 t_table	table;
	//  char *argv[6] = {"./philo_bonus", "1", "800", "200", "200", NULL};
	//  char argc = sizeof(argv) / sizeof(argv[0]);
    // struct sigaction sa;
    // sa.sa_handler = handle_sigchld;
    // sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;  // restart syscalls, ignore stopped children
    // sigemptyset(&sa.sa_mask);

    // if (sigaction(SIGCHLD, &sa, NULL) == -1) {
    //     perror("sigaction");
    //     exit(EXIT_FAILURE);
    // }

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&table, argv) == ERROR_PARSE)
			return (FAILURE);
		if (init_data(&table) == ERROR_INIT)
		{
			clean_up(&table);
			return (FAILURE);
		}
		if (dinner_start(&table) == ERROR_DINNER_START)
		{
			clean_up(&table);
			return (FAILURE);
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
