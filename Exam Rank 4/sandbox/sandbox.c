/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:25:33 by thchau            #+#    #+#             */
/*   Updated: 2025/09/13 19:30:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

static void nice_function()
{	
}

static void bad_function()
{
	exit(1);
}

static void seg_function()
{
	char *p;
	p = NULL;
	*p = 5;
}

static void infinite_loop()
{
	while(1);
}

static void killed_by_sigkill()
{
	kill(getpid(), SIGKILL);
}

static void killed_by_sigterm()
{
	kill(getpid(), SIGTERM);
}
static void killed_by_sigstop()
{
	kill(getpid(), SIGSTOP);
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int status;
	pid_t pid;
	time_t start;

	if (!f)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		f();
		exit(0);
	}
	else
	{
		start = time(NULL);
		while(1)
		{// WNOHANG
		// Means: don’t block if the child hasn’t changed state yet.
		// If you call waitpid with WNOHANG and the child is still running normally, waitpid returns 0 immediately instead of waiting.
		// This is useful if you want to “poll” the child’s status in a loop (like you do for timeout handling).
		// UNTRACED some systems won’t report stop states unless you add WUNTRACED.
			pid_t w = waitpid(pid, &status, WNOHANG | WUNTRACED);
			if (w == -1)
				return (-1);
			else if (w == 0)
			{
				// Children is still running
				if (timeout > 0 && time(NULL) - start >= timeout)
				{
					kill(pid, SIGKILL);
					waitpid(pid, &status, 0);
					if (verbose)
						printf("Bad function: timed out after %i seconds\n", timeout);
					return (0);
				}
				usleep(100000);
			}
			else
			{
				// Children exited;
				if (WIFEXITED(status))
				{
					int code = WEXITSTATUS(status);
					if (code == 0)
					{
						if (verbose)
							printf("Nice function!\n");
						return (1);
					}
					else
					{
						if (verbose)
							printf("Bad function: exited with code %i\n", code);
						return (0);
					}
				}
				else if (WIFSIGNALED(status))
				{
					int sig = WTERMSIG(status);
					if (verbose)
						printf("Bad function: %s\n", strsignal(sig));
					return (0);
				}
				else if (WIFSTOPPED(status))
				{
					int sig = WSTOPSIG(status);
					if (verbose)
						printf("Bad function: %s\n", strsignal(sig));
					return (0);
				}
				
			}
		}
	}
}

int main()
{
	printf("Testing nice func \n");
	sandbox(nice_function, 2, true);
	printf("\n");
	printf("Testing bad function with exit code = 1 \n");
	sandbox(bad_function, 2, true);
	printf("\n");
	printf("Testing segfault function \n");
	sandbox(seg_function, 2, true);
	printf("\n");
	printf("Tesing timeout function \n");
	sandbox(infinite_loop, 2, true);
	printf("\n");
	printf("Tesing terminated signal function \n");
	sandbox(killed_by_sigterm, 2, true);
	printf("\n");
	printf("Tesing stopped signal function \n");
	sandbox(killed_by_sigstop, 2, true);
	printf("\n");
	printf("Tesing kill signal function \n");
	sandbox(killed_by_sigkill, 2, true);
	return(0);
}