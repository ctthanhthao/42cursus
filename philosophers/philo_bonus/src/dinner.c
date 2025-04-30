/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:00:28 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 22:34:57 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	kill_all_philos(t_table *tb)
{
	int	i;

	if (!tb)
		return ;
	i = 0;
	while (i < tb->philo_nbr)
	{
		if (kill(tb->philos[i].pid, SIGKILL) == -1)
		{
			if (errno != ESRCH) // ESRCH: No such process
				perror("Failed to kill philosopher");
		}
		i++;
	}
}

void monitor_exit_codes(t_table *tb)
{
	int		status;
	pid_t	pid;
	int		count_full_philo = 0;

	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
        {
            if (errno == ECHILD)
                break; // No more child processes
            else
			{
				perror("waitpid failed");
				continue;
			}
        }
		if (WIFEXITED(status)) {
			switch (WEXITSTATUS(status))
			{
				case EXIT_PHILO_DIED:
					kill_all_philos(tb);
					return;
				case EXIT_PHILO_FULL:
					count_full_philo++;
					if (count_full_philo == tb->philo_nbr)
						return;
			}
		}
	}
}
/*
* 1. if num of meal = 0, return
* 2. If philo is only one, it will die
* 3. create all threads.
* 4. wait until all threads are created, start a monitor
* which goes to check if any thread dies or all threads are full. 
-> end simulation 
*/
t_error_code	dinner_start(t_table *tb)
{
	if (tb->nbr_limit_meal == 0)
		return (SUCCESS);
	if (tb->philo_nbr == 1)
		return (one_philo_process(tb));
	else
	{
		tb->start_simulation = get_time(MILLISECOND);
		if (trigger_philos_processes(tb) == FAILURE)
			return (ERROR_DINNER_START);
		monitor_exit_codes(tb);
	}
	return (SUCCESS);
}
