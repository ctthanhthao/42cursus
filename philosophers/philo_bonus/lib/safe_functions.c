/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:11:17 by thchau            #+#    #+#             */
/*   Updated: 2025/04/30 21:11:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
	{
		log_error("Error with malloc.");
		return (NULL);
	}
	memset(ret, 0, bytes);
	return (ret);
}

static t_error_code	handle_thread_error(int status, t_opcode code)
{
	if (status == 0)
		return (SUCCESS);
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

t_error_code	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
									void *data, t_opcode code)
{
	if (code == CREATE)
		return (handle_thread_error(pthread_create(thread, NULL, foo, data),
				CREATE));
	else if (code == JOIN)
		return (handle_thread_error(pthread_join(*thread, NULL), JOIN));
	else if (code == DETACH)
		return (handle_thread_error(pthread_detach(*thread), DETACH));
	else
	{
		log_error("Wrong opcode for thread handle.");
		return (ERROR_THREAD);
	}
}
