/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:37:00 by thchau            #+#    #+#             */
/*   Updated: 2026/04/16 19:15:15 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static bool	is_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static void	free_rgb_parts(char **parts, char *r, char *g, char *b)
{
	free_arr(parts);
	free(r);
	free(g);
	free(b);
}

static const char	*skip_color_prefix(const char *line)
{
	while (*line == 'F' || *line == 'C')
		line++;
	while (ft_isspace(*line))
		line++;
	return (line);
}

static int	set_color(int *field, char *r, char *g, char *b)
{
	int		rv;
	int		gv;
	int		bv;

	rv = ft_atoi(r);
	gv = ft_atoi(g);
	bv = ft_atoi(b);
	if (rv < 0 || rv > 255 || gv < 0 || gv > 255 || bv < 0 || bv > 255)
		return (log_err("RGB out of range"), FAILURE);
	*field = (rv << 16) | (gv << 8) | bv;
	return (SUCCESS);
}

int	set_rgb_line(int *field, const char *line)
{
	char	**parts;
	char	*r;
	char	*g;
	char	*b;

	line = skip_color_prefix(line);
	parts = ft_split(line, ',');
	if (!parts || ft_arrlen(parts) != 3)
		return (free_arr(parts), log_err("Invalid color"), FAILURE);
	r = ft_trim(parts[0]);
	g = ft_trim(parts[1]);
	b = ft_trim(parts[2]);
	if (!is_number(r) || !is_number(g) || !is_number(b))
		return (free_rgb_parts(parts, r, g, b), log_err("Invalid RGB"),
			FAILURE);
	set_color(field, r, g, b);
	free_rgb_parts(parts, r, g, b);
	return (SUCCESS);
}
