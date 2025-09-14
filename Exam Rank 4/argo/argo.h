/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:22:52 by thchau            #+#    #+#             */
/*   Updated: 2025/09/14 18:08:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGO_H
# define ARGO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
	JSON_NUMBER,
	JSON_STRING,
	JSON_OBJECT
} json_type;

typedef struct json
{
	json_type type;
	int number;
	char *str;
	struct pair *map;
} json;

typedef struct pair
{
	char *key;
	struct json *value;
	struct pair *next;
} pair;

int	argo(json *dst, FILE *stream);

#endif