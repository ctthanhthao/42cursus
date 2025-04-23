/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:38:02 by thchau            #+#    #+#             */
/*   Updated: 2025/04/20 17:47:16 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_length(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

long	get_time(t_time_code tc)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		log_error("Failed in gettimeofday function.");
		return (-1);
	}
	if (tc == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (tc == MILLISECOND)
		return (tv.tv_sec * 1e3 + (tv.tv_usec / 1e3));
	else if (tc == MICROSECOND)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else
	{
		log_error("Time code is incorrect.");
		return (-1);
	}
}

void	custom_usleep(long usec)
{
	long	start;
	long	elapsed;
	long	rem;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		elapsed = get_time(MICROSECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}
