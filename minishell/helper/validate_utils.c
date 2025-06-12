/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:27:32 by amarcz            #+#    #+#             */
/*   Updated: 2025/05/31 21:29:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quoted(char *token)
{
	int	len;

	len = ft_strlen(token);
	if ((token[0] == '\'' && token[len - 1] == '\'')
		|| (token[0] == '\"' && token[len - 1] == '\"'))
		return (1);
	return (0);
}
