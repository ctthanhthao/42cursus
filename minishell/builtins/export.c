/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:26:01 by thchau            #+#    #+#             */
/*   Updated: 2025/05/31 20:57:47 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	build_key_value(const char *new_var, int key_len, char **key,
	char **value)
{
	char	*tmp;

	tmp = (char *)(new_var + key_len + 1);
	*value = remove_quotes_if_need(tmp);
	*key = ft_substr(new_var, 0, key_len + 1);
}

static char	**add_env_var(char **envp, const char *new_var, int key_len)
{
	int			i;
	char		**new_envp;
	char		*key;
	char		*value;

	i = 0;
	while (envp[i])
		i++;
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (envp[++i])
		new_envp[i] = ft_strdup(envp[i]);
	if (new_var[key_len] == '=')
	{
		build_key_value(new_var, key_len, &key, &value);
		new_envp[i] = ft_strjoin_free(key, value);
		free(value);
	}
	else
		new_envp[i] = ft_strdup(new_var);
	return (new_envp[i + 1] = NULL, free_split(envp), new_envp);
}

static bool	update_env(char **entry_env, const char *new_var, size_t key_len)
{
	char		*value;
	char		*key;

	if (!new_var[key_len])
		return (true);
	else if (new_var[key_len] == '=')
	{
		build_key_value(new_var, key_len, &key, &value);
		free(*entry_env);
		*entry_env = ft_strjoin_free(key, value);
		free(value);
		return (true);
	}
	else
		return (false);
}

static char	**update_or_add_env(char **envp, const char *new_var)
{
	char	*key;
	int		i;
	size_t	key_len;

	key = extract_key(new_var);
	if (!key)
		return (NULL);
	key_len = ft_strlen(key);
	i = -1;
	while (envp[++i])
	{
		if ((ft_strncmp(envp[i], key, key_len) == 0) && (!envp[i][key_len]
			|| envp[i][key_len] == '='))
		{
			if (update_env(&envp[i], new_var, key_len))
			{
				free(key);
				return (envp);
			}
			break ;
		}
	}
	free(key);
	return (add_env_var(envp, new_var, key_len));
}

int	export_builtin(t_cmd *cmd, char ***envp)
{
	int		i;
	int		status;
	char	*new_var;

	status = CMD_SUCCESS;
	if (!envp || !*envp)
		return (log_errno("env is null"), CMD_FAILURE);
	if (!cmd->argv[1])
		return (print_sorted_env(*envp), CMD_SUCCESS);
	i = 0;
	while (cmd->argv[++i])
	{
		new_var = strip_quotes(cmd->argv[i]);
		status = check_valid_identifier(new_var);
		if (status == CMD_FAILURE)
		{
			free(new_var);
			continue ;
		}
		*envp = update_or_add_env(*envp, new_var);
		free(new_var);
		if (!*envp)
			return (log_errno("memory allocation failed"), CMD_FAILURE);
	}
	return (status);
}
