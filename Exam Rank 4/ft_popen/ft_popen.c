/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:57:48 by thchau            #+#    #+#             */
/*   Updated: 2025/09/13 14:02:31 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	pid_t pid;
	int fd[2];
	
	if (!file || !argv || (type != 'w' && type != 'r'))
		return (-1);
	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit (1);
		}
		else if (type == 'w')
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	else
	{
		if (type == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		else if (type == 'w')
		{
			close(fd[0]);
			return (fd[1]);
		}
	}
	return (-1);	
}

int main (void)
{
	char buffer[256];
	int fd;
	ssize_t n;

	char *argv_ls[] = {"ls", "-l", NULL};
	fd = ft_popen("ls", argv_ls, 'r');
	if (fd == -1)
	{
		perror("ft_popen failed");
		return (1);
	}
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "2d", NULL}, 'r');
	printf("Output of ls -l: \n");
	while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[n] = '\0';
		printf("%s", buffer);
	}
	close(fd);
	
	char *argv_cat[] = {"cat", NULL};
	fd = ft_popen("cat", argv_cat, 'w');
	if (fd == -1)
	{
		perror("ft_popen failed");
		return (1);
	}
	const char *msg = "Hello from ft_popen write test!\n";
	write(fd, msg, strlen(msg));
	close(fd);
	return (0);
}