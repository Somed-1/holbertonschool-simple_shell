#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 64
#define DELIMS " \t\r\n"

char **parse_line(char *command)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
		return(NULL);

	char *arg = strtok(command, DELIMS);
	int i = 0;

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
	size_t len = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		read = getline(&command, &len, STDIN_FILENO);
		if (read == -1)
		{
			perror("Error: can't read from stdin\n");
			return (1);
		}

		char **args = parse_line(command);

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

			for (int i = 0; args[i] != NULL; i++)
				free(args[i]);
		}

		free(args);
	}

	free(command);
	return (0);
}
