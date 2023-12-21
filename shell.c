#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 64
#define DELIMS " \t\r\n"

char **parse_line(char *command)
{
	char *arg, **args;
	int i;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
		return(NULL);

	arg = strtok(command, DELIMS);
	i = 0;

	while (arg != NULL && i < MAX_ARGS - 1)
	{
		args[i] = strdup(arg);
		i++;
		arg = strtok(NULL, DELIMS);
	}

	args[i] = NULL;
	return args;
}

int main(void)
{
	char *command = NULL;
	char **args;
	size_t len = 0;
	ssize_t read;
	int i;
	pid_t pid;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}


		read = getline(&command, &len, stdin);

		if (read == -1)
		{
			fflush(stdin);
			free(command);
			break;
		}

		args = parse_line(command);

		if (args != NULL && args[0] != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(args[0], args, NULL);
				perror("execve failed");
				exit(1);
			}
			else
			{
				wait(NULL);
			}

			for (i = 0; args[i] != NULL; i++)
				free(args[i]);

			free(args);
		}

		free(command);
		command = NULL;
	}

	return (0);
}
