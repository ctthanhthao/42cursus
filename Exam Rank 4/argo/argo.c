/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:21:52 by thchau            #+#    #+#             */
/*   Updated: 2025/09/14 19:36:27 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argo.h"

int parse_value(json *dst, FILE *f);
void print_json(json *file);
void free_json(json *j);

void free_object(pair *map)
{
	while(map)
	{
		pair *next = map->next;
		free(map->key);
		free_json(map->value);
		free(map);
		map = next;
	}
}

void free_json(json *j)
{
	if (j->type == JSON_STRING)
		free(j->str);
	else if (j->type == JSON_OBJECT)
		free_object(j->map);
	free(j);
}

static void print_error(char c)
{
	if (c == EOF)
	{
		printf("Unexpected end of input\n");
	}
	else
		printf("Unexpected token '%c'\n", c);
}

static int parse_number(json *dst, FILE *f)
{
	int number;
	int negative;
	int c;
	
	negative = 1;
	number = 0;
	c = getc(f);
	if (c == '-')
	{
		negative = -1;
		c = getc(f);
	}
	if (!isdigit(c))
	{
		print_error(c);
		return -1;
	}
	while(isdigit(c))
	{
		number = number * 10 + (c - '0');
		c = getc(f);
	}
	ungetc(c, f);
	dst->type = JSON_NUMBER;
	dst->number = number * negative;
	return 1;
}

static int parse_string(json *dst, FILE *f)
{
	int c;
	size_t capacity = 16;
	size_t len = 0;
	char *buf = malloc(capacity);
	
	c = getc(f);
	while (c != '\"')
	{
		if (c == EOF)
		{
			printf("Unexpected end of input\n");
			free(buf);
			return -1;
		}
		if (c == '\\')
		{
			int next = getc(f);
			if (next == '"' || next == '\\')
				c = next;
			else 
			{
				print_error(next);
				free(buf);
				return -1;
			}
		}
		if (len + 1 >= capacity)
		{
			capacity *= 2;
			char *tmp = realloc(buf, capacity);
			if (!tmp)
			{
				free(buf);
				return -1;
			}
			buf = tmp;
		}
		buf[len++] = (char)c;
		c = getc(f);
	}
	buf[len] = '\0';
	dst->type = JSON_STRING;
	dst->str = buf;
	return 1;
}

static int parse_object(json *dst, FILE *f)
{
	int c;
	pair *head = NULL;
	pair *tail = NULL;
	
	c = getc(f);
	if (c == '}')
	{
		dst->type = JSON_OBJECT;
		dst->map = NULL;
		return 1;
	}
	ungetc(c, f);
	while (1)
	{
		c = getc(f);
		if (c != '"')
		{
			print_error(c);
			return -1;
		}
		json keyjson;
		if (parse_string(&keyjson, f) == -1)
			return -1;
		c = getc(f);
		if (c != ':')
		{
			print_error(c);
			free(keyjson.str);
			return -1;
		}
		json *val = malloc(sizeof(json));
		if (!val)
			return -1;
		if (parse_value(val, f) == -1)
		{
			free(keyjson.str);
			free(val);
			return -1;
		}
		pair *map = malloc(sizeof(pair));
		if (!map)
			return -1;
		map->key = keyjson.str;
		map->value = val;
		map->next = NULL;
		if (!head)
			head = map;
		if(tail)
			tail->next = map;
		tail = map;	
		c = getc(f);
		if (c == '}')
			break;
		if (c != ',')
		{
			print_error(c);
			free_object(head);
			return -1;
		}
	}
	
	dst->type = JSON_OBJECT;
	dst->map = head;
	return 1;
}

int parse_value(json *dst, FILE *f)
{
	int c = getc(f);
	if (c == EOF)
	{
		printf("Unexpected end of input\n");
		return (-1);
	}
	if (c == '"')
		return parse_string(dst, f);
	if (c == '{')
		return parse_object(dst, f);
	if (isdigit(c) || c == '-')
	{
		ungetc(c, f);
		return parse_number(dst, f);
	}
	printf("Unexpected token '%c'\n", c);
	return -1;
}

int	argo(json *dst, FILE *stream)
{
	return parse_value(dst, stream);
}

static void print_object(pair *p)
{
	pair *tmp;
	int i;
	char c;
	
	tmp = p;
	while (tmp)
	{
		putchar('"');
		i = 0;
		while(tmp->key[i])
		{
			c = tmp->key[i];
			if (c == '\\' || c == '"')
				printf("\\%c", c);
			else
				putchar(c);
			i++;
		}
		putchar('"');
		putchar(':');
		print_json(tmp->value);
		tmp = tmp->next;
		if (tmp)
			putchar(',');
	}
}

void print_json(json *file)
{
	int i;
	char c;
	
	if (!file)
		return;
	if (file->type == JSON_NUMBER)
		printf("%d", file->number);
	else if (file->type == JSON_STRING)
	{
		i = 0;
		putchar('"');
		while(file->str[i])
		{
			c = file->str[i];
			if (c == '\\' || c == '"')
				printf("\\%c", c);
			else
				putchar(c);
			i++;
		}
		putchar('"');
	}
	else if (file->type == JSON_OBJECT)
	{
		putchar('{');
		print_object(file->map);
		putchar('}');
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	if (!stream)
		return (1);
	json *file = malloc(sizeof(json));
	if (argo(file, stream) != 1)
	{
		fclose(stream);
		return (1);
	}
	fclose(stream);
	print_json(file);
	printf("\n");
	free_json(file);
	return 0;
}