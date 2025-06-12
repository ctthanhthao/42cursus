/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_restore_redirections.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:59:13 by thchau            #+#    #+#             */
/*   Updated: 2025/05/29 12:24:29 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	save_original_std_inout(int *stdin_bk, int *stdout_bk)
{
	*stdout_bk = dup(STDOUT_FILENO);
	if (*stdout_bk == -1)
	{
		log_errno("Error saving STDOUT_FILENO");
		return (false);
	}
	*stdin_bk = dup(STDIN_FILENO);
	if (*stdin_bk == -1)
	{
		log_errno("Error saving STDIN_FILENO");
		return (false);
	}
	return (true);
}

void	restore_original_std_inout(int stdin_bk, int stdout_bk)
{
	if (stdout_bk != -1)
	{
		dup2(stdout_bk, STDOUT_FILENO);
		close(stdout_bk);
	}
	if (stdin_bk != -1)
	{
		dup2(stdin_bk, STDIN_FILENO);
		close(stdin_bk);
	}
}
