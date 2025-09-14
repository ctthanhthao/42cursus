/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:40:53 by thchau            #+#    #+#             */
/*   Updated: 2025/09/13 20:34:00 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct s_parser
{
	const char *input;
	int pos;
	char curr;	
} t_parser;

int parse_exp(t_parser *data);

static void parse_init(t_parser *p, const char *exp)
{
	p->input = exp;
	p->pos = 0;
	p->curr = exp[0]; 
}

static void print_error(char c)
{
	if (c == '\0')
	{
		printf("Unexpected end of input\n");
	}
	else
		printf("Unexpected token '%c'\n", c);
	exit(1);
}

static void advance(t_parser *p)
{
	if (p->curr != '\0')
	{
		p->pos += 1;
		p->curr = p->input[p->pos];
	}
}

int parse_factor(t_parser *data)
{
	int value;
	
	if (isdigit((unsigned char)data->curr))
	{
		value = data->curr - '0';
		advance(data);
		return value;
	}
	if (data->curr == '(')
	{
		advance(data);
		value = parse_exp(data);
		if (data->curr != ')')
			print_error(data->curr);
		advance(data);
		return value;
	}
	print_error(data->curr);
	return (0);
}

int parse_term(t_parser *data)
{
	int value = parse_factor(data);
	while (data->curr == '*')
	{
		advance(data);
		value *= parse_factor(data);
	}
	return (value);
}

int parse_exp(t_parser *data)
{
	int value = parse_term(data);
	while (data->curr == '+')
	{
		advance(data);
		value += parse_term(data);
	}
	return (value);
}

int main(int argc, char **argv)
{
	int result;
	t_parser data;
	
	if (argc != 2)
	{
		write(2, "Usage: ", 8);
		write(2, argv[0], strlen(argv[0]));
		write(2, " <expression> ", 15);
		write(2, "\n", 1);
		return (1);
	}
	parse_init(&data, argv[1]);
	result = parse_exp(&data);
	printf("%i\n", result);
	return (0);
}