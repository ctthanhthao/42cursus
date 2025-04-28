/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:00:28 by thchau            #+#    #+#             */
/*   Updated: 2025/04/28 08:41:02 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*handle_dead_process(void *data)
{
	t_table	*tb;
	int		status;
	pid_t	pid;
	int		i;

	tb = (t_table *)data;
	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			i = 0;
			while (i < tb->philo_nbr)
			{
				printf("kill process.....\n");
				kill(tb->philos[i].pid, SIGKILL);
				i++;
			}
		}
	}
	return (NULL);
}

/*
* 1. if num of meal = 0, return
* 2. If philo is only one, it will die
* 3. create all threads.
* 4. wait until all threads are created, start a monitor
* which goes to check if any thread dies. 
-> end simulation 
*/
t_error_code	dinner_start(t_table *tb)
{
	pthread_t	monitor_tid;

	if (tb->nbr_limit_meal == 0)
		return (SUCCESS);
	if (tb->philo_nbr == 1)
		return (one_philo_process(tb));
	else
	{
		tb->start_simulation = get_time(MILLISECOND);
		if (init_trigger_philos_processes(tb) == FAILURE)
			return (log_error("Failed to trigger philos processes."),
				ERROR_DINNER_START);
		if (safe_thread_handle(&monitor_tid, handle_dead_process, tb, CREATE)
			== ERROR_THREAD)
		{
			log_error("Failed to create thread of dead process handle.");
			return (ERROR_DINNER_START);
		}
		if (safe_thread_handle(&monitor_tid, NULL, NULL, JOIN) == ERROR_THREAD)
			return (log_error("Failed to join thread of dead process handle."),
				ERROR_DINNER_START);
	}
	return (SUCCESS);
}
