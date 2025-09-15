/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:52:05 by thchau            #+#    #+#             */
/*   Updated: 2025/09/15 11:27:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void printstr(char *s)
{
	while(*s)
		write(1, s++, 1);
	write(1, "\n", 1);
}

static int valid(char *s)
{
	int bal = 0;
	int i = 0;
	if (!s)
		return 1;
	while (s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			if (bal == 0)
				return 0;
			bal--;
		}
		i++;
	}	
	return (bal == 0);
}

static void dfs(char *s, int start, int remL, int remR)
{
	int i;
	char c;
	
	if (remL == 0 && remR == 0)
	{
		if (valid(s) == 1)
			printstr(s);
		return;
	}
	i = start;
	while(s[i])
	{
		if (s[i] == ')' && remR > 0)
		{
			c = s[i];
			s[i] = ' ';
			dfs(s, i + 1, remL, remR - 1);
			s[i] = c;
		}
		else if (s[i] == '(' && remL > 0)
		{
			c = s[i];
			s[i] = ' ';
			dfs(s, i + 1, remL - 1, remR);
			s[i] = c;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int bal = 0;
	int remL = 0;
	int remR = 0;
	int i = 0;
	char *s;
	
	if (argc != 2)
	{
		write(2, "Usage: ", 8);
		write(2, "./rip ", 7);
		write(2, "<parenthesises>", 16);
		write(2, "\n", 1);
		return (1);
	}
	s = argv[1];
	while(s[i])
	{
		if (s[i] == '(')
			bal++;
		else if (s[i] == ')')
		{
			if (bal == 0)
				remR++;
			else
				bal--;
		}
		i++;
	}
	remL = bal;
	dfs(s, 0, remL, remR);
	return 0;
}