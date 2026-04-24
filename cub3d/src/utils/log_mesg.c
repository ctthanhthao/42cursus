/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_mesg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:05:29 by thchau            #+#    #+#             */
/*   Updated: 2026/03/30 18:25:24 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define R	"\033[31m"
#define RST	"\033[0m"

void	log_err(char *error_msg)
{
	write(STDERR_FILENO, R, ft_strlen(R));
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, RST, ft_strlen(RST));
	write(STDERR_FILENO, "\n", 1);
}
