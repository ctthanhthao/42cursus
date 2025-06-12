/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_file_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:50:14 by thchau            #+#    #+#             */
/*   Updated: 2025/05/30 14:08:17 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	is_existing_path(const char *path)
{
	struct stat	sb;

	return (path && stat(path, &sb) == 0);
}

bool	has_file_arguments(t_cmd *cmd)
{
	int		i;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	i = 1;
	while (cmd->argv[i])
	{
		if (cmd->argv[i][0] != '-' && is_existing_path(cmd->argv[i]))
			return (true);
		i++;
	}
	return (false);
}
