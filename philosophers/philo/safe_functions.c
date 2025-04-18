/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:17 by thchau            #+#    #+#             */
/*   Updated: 2025/04/18 11:33:51 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
	{
		log_error("Error with malloc.");
		return (NULL);
	}
	return (ret);	
}

static t_error_code handle_mutex_error(int status, t_opcode code)
{
	if (status == 0)
		return SUCCESS;
	if (status == EINVAL && (code == LOCK || code == UNLOCK ||
		code == DESTROY))
		log_error("The value specified by mutex is invalid.");
	else if (status == EINVAL && code == INIT)
		log_error("The value specified by attr is invalid.");
	else if (status == ENOMEM)
		log_error("The process cannot allocate enough memory to create"
                        "another mutex.");
	else if (status == EPERM)
		log_error("The current thread does not hold a lock on mutex.");
	else if (status == EDEADLK)
		log_error (" A deadlock would occur if the thread blocked waiting"
                        "for mutex.");
	else if (status == EBUSY)
		log_error("Mutex is locked.");
	else
		log_error("Unknown error happens for mutex");
	return (ERROR_MUTEX);
}

t_error_code	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		return (handle_mutex_error(pthread_mutex_lock(mutex), LOCK));
	else if (opcode == UNLOCK)
		return (handle_mutex_error(pthread_mutex_unlock(mutex), UNLOCK));
	else if (opcode == INIT)
		return (handle_mutex_error(pthread_mutex_init(mutex, NULL), INIT));
	else if (opcode == DESTROY)
		return (handle_mutex_error(pthread_mutex_destroy(mutex), DESTROY));
	else
	{
		log_error("Wrong opcode for mutex handle.");
		return (ERROR_MUTEX);
	}
}

static t_error_code	handle_thread_error(int status, t_opcode code)
{
	if (status == 0)
		return SUCCESS;
	if (status == EINVAL && (code == CREATE))
		log_error("The value specified by attr is invalid.");
	else if (status == EINVAL && code == JOIN)
		log_error("the value specified by thread does not refer to a"
			" joinable thread.");
	else if (status == EAGAIN)
		log_error("The system lacked the necessary resources to create"
            " another thread");
	else if (status == EPERM)
		log_error("The caller does not have appropriate permission.");
	else if (status == EDEADLK)
		log_error ("A deadlock was detected.");
	else if (status == ESRCH)
		log_error(" No thread could be found.");
	else
		log_error("Unknown error happens for thread");
	return (ERROR_THREAD);
}

t_error_code safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
	t_opcode code)
{
	if (code == CREATE)
		return (handle_thread_error(pthread_create(thread, NULL, foo, data), CREATE));
	else if (code == JOIN)
		return (handle_thread_error(pthread_join(*thread, NULL), JOIN));
	else
	{
		log_error("Wrong opcode for thread handle.");
		return (ERROR_THREAD);	
	}
}