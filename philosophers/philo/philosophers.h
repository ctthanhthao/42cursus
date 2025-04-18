/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:09:59 by thchau            #+#    #+#             */
/*   Updated: 2025/04/16 21:17:30 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_philo_action
{
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_philo_action;

typedef enum e_time_code 
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

/*
* OPCODE for mutex and thread functions 
*/
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
} t_opcode;

typedef struct s_table t_table;
typedef struct s_fork 
{
	int				fork_id;
	pthread_mutex_t fork;
} 	t_fork;

/*
*   /.philo 5 100 200 300 [3]
*
*/
typedef struct s_philo {
	int 			id;
	pthread_t 		thread;
	long 			last_meal_time;
	int 			num_of_meals;
	bool			is_full;
	bool			is_dead;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_table			*table;
	pthread_mutex_t mtx;
} t_philo;

struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meal;
	long	start_simulation;
	bool	all_threads_ready;
	bool	end_simulation;
	t_philo	*philos;
	t_fork	*forks;
	pthread_mutex_t	access_mtx;
	pthread_mutex_t write_mtx;
};

typedef enum e_error_code
{
	SUCCESS = 0,
	ERROR_PARSE = -1,
	INVALID_INPUT = -11,
	ERROR_INIT = -2,
	ERROR_MUTEX = -22,
	ERROR_THREAD = -23,
	ERROR_SET_BOOL = -31,
	ERROR_GET_BOOL = -32,
	ERROR_DINNER_START = -4,
	ERROR_PHILO_START =  -41,
	ERROR_START_MONITOR = -43,
	THREAD_DIED = -44,
} t_error_code;

void	log_error(const char *error);
void	log_message(char *msg);
int		ft_length(const char *s);
void	*safe_malloc(size_t bytes);
long	get_time(t_time_code tc);
int		is_space(char c);
int		is_digit(char c);
void	custom_usleep(long usec);
bool	log_action(t_philo_action action, t_philo *philo);

void	set_bool(pthread_mutex_t *mtx, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mtx, bool *dest);
bool	simulation_finished(t_table *tb);
t_error_code	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
	t_opcode code);
t_error_code	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
t_error_code	parse_input(t_table *tb, char **argv);
t_error_code	data_init(t_table *tb);
t_error_code	dinner_start(t_table *tb);
void	clean_up(t_table *tb);

t_error_code	philo_eats(t_philo *philo);
void			philo_sleeps(t_philo *philo);
void			philo_thinks(t_philo *philo);
#endif