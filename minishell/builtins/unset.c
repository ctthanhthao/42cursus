/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:32:07 by thchau            #+#    #+#             */
/*   Updated: 2025/05/25 17:06:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static bool	check_env_exists(char **envp, char *var_name)
{
	int		i;
	int		var_len;

	i = 0;
	var_len = ft_strlen(var_name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var_name, var_len) == 0
			&& (envp[i][var_len] == '=' || envp[i][var_len] == '\0'))
			return (true);
		i++;
	}
	return (false);
}

static void	handle_unset(char *env, char **new_envp, char *var_name, int *j)
{
	if (ft_strncmp(env, var_name, ft_strlen(var_name)) == 0
		&& (env[ft_strlen(var_name)] == '='
			|| env[ft_strlen(var_name)] == '\0'))
		free(env);
	else
	{
		new_envp[*j] = ft_strdup(env);
		(*j)++;
		free(env);
	}
}

static void	unset_env_var(char ***envp, char *var_name)
{
	int		len_env;
	char	**new_envp;
	int		i;
	int		j;

	len_env = 0;
	i = 0;
	j = 0;
	if (!check_env_exists(*envp, var_name))
		return ;
	while ((*envp)[len_env])
		len_env++;
	new_envp = malloc(sizeof(char *) * len_env);
	if (new_envp == NULL)
		return ;
	while ((*envp)[i])
	{
		handle_unset((*envp)[i], new_envp, var_name, &j);
		i++;
	}
	new_envp[j] = NULL;
	free(*envp);
	*envp = new_envp;
}

int	unset_builtin(t_cmd *cmd, char ***envp)
{
	int		i;

	if (cmd->argv[1] == NULL)
		return (CMD_SUCCESS);
	i = 1;
	while (cmd->argv[i])
	{
		unset_env_var(envp, cmd->argv[i]);
		i++;
	}
	return (CMD_SUCCESS);
}
