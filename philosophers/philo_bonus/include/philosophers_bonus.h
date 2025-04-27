/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:09:59 by thchau            #+#    #+#             */
/*   Updated: 2025/04/27 17:15:27 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define RST		"\033[0m" // Reset formatting
# define R			"\033[31m" // Red
# define G			"\033[32m" // Green
# define Y			"\033[33m" // Yellow
# define B			"\033[34m" // Blue

# define DEBUG_MODE 0

# define SEM_WRITE_FNAME "/write"
# define SEM_SYNC_START_FNAME "/sync_start"
# define SEM_LAST_MEAL_FNAME "/last meal"
# define SEM_FORK_FNAME "/fork"

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
* OPCODE for sem and thread functions 
*/
typedef enum e_opcode
{
	OPEN,
	WAIT,
	POST,
	CLOSE,
	UNLINK,
	JOIN,
	CREATE,
	DESTROY,
	DETACH
}	t_opcode;

typedef struct s_table	t_table;

typedef struct s_fork
{
	int		id;
	char	*name;
	sem_t	*sem_fork;
}	t_fork;

/*
*   /.philo 5 100 200 300 [3]
*
*/
typedef struct s_philo
{
	int			id;
	pid_t		pid;
	long		last_meal_time;
	int			num_of_meals;
	bool		is_full;
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_table		*table;
}	t_philo;

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meal;
	long		start_simulation;
	t_philo		*philos;
	t_fork		*forks;
	sem_t		*sem_write;
	sem_t		*sem_start; // Sync start time for all philos
	sem_t		*sem_last_meal; // protect last meal
	pthread_t	monitor_dead;
};

typedef enum e_error_code
{
	SUCCESS = 0,
	FAILURE = 1,
	ERROR_PARSE = -1,
	INVALID_INPUT = -11,
	ERROR_INIT = -2,
	ERROR_THREAD = -23,
	ERROR_DINNER_START = -4
}	t_error_code;

void			log_error(const char *error);
int				ft_length(const char *s);
long			get_time(t_time_code tc);
int				is_space(char c);
int				is_digit(char c);
void			custom_usleep(long usec);
int				ft_strlen(const char *s);
char			*ft_itoa(int n);
char			*ft_strjoin(char *s1, char *s2);

void			*safe_malloc(size_t bytes);
sem_t			*safe_sem_open(const char *name, int oflag, mode_t mode,
					unsigned int value);
void			safe_sem_wait(sem_t *sem, const char *name);
void			safe_sem_post(sem_t *sem, const char *name);
void			safe_sem_close(sem_t *sem, const char *name);
void			safe_sem_unlink(const char *name);
t_error_code	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
					void *data, t_opcode code);

void			log_action(t_philo_action action, t_philo *philo);

t_error_code	parse_input(t_table *tb, char **argv);
t_error_code	init_data(t_table *tb);
t_error_code	dinner_start(t_table *tb);
t_error_code	one_philo_process(t_table *tb);
t_error_code	trigger_monitor_death(t_philo *philo);
int				init_trigger_philos_processes(t_table *tb);

void			philo_eats(t_philo *philo);
void			philo_sleeps(t_philo *philo);
void			philo_thinks(t_philo *philo);
void			clean_up(t_table *tb);

#endif