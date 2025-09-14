/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:07:45 by thchau            #+#    #+#             */
/*   Updated: 2025/09/13 15:27:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int    picoshell(char **cmds[])
{
	int i = 0;
	int prev_fd = -1;
	pid_t pid;
	int fd[2];
	int status;
	
	if (!cmds || !*cmds)
		return (1);
	while (cmds[i])
	{
		if (cmds[i + 1])
		{
			if (pipe(fd) == -1)
				return (1);
		}
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
		{
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
				{
					close(fd[0]);
					close(fd[1]);
					exit(1);
				}
				close(prev_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if (prev_fd != -1)
				close(prev_fd);
			close(fd[1]);
			if (cmds[i + 1])
				prev_fd = fd[0];
		}
		i++;
	}
	while (wait(&status) > 0);
	return (0);
}

void print_cmds(char **argv[])
{
	int i = 0;
	int j = 0;
	while (argv[i])
	{
		j = 0;
		printf("cmd %i: ", i);
		while (argv[i][j])
		{
			printf("%s ", argv[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static int count_cmds(int argc, char **argv)
{
	int i = 1;
	int count = 0;
	
	if (!argv)
		return count;
	count += 1;
	while (i < argc)
	{
		if (strcmp(argv[i], "|"))
			count++;
		i++;
	}
	return count;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

	int	cmd_count = count_cmds(argc, argv);
	char	***cmds = calloc(cmd_count + 1, sizeof(char **));
	if (!cmds)
		return (perror("calloc"), 1);

	int	i = 1, j = 0;
	while (i < argc)
	{
		int	len = 0;
		while (i + len < argc && strcmp(argv[i + len], "|") != 0)
			len++;
		cmds[j] = calloc(len + 1, sizeof(char *));
		if (!cmds[j])
			return (perror("calloc"), 1);
		for (int k = 0; k < len; k++)
			cmds[j][k] = argv[i + k];
		cmds[j][len] = NULL;
		i += len + 1;
		j++;
	}
	cmds[cmd_count] = NULL;
//	print_cmds(cmds);
	int	ret = picoshell(cmds);

	// Clean up
	for (int i = 0; cmds[i]; i++)
		free(cmds[i]);
	free(cmds);

	return (ret);
}