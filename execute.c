#include "shell.h"

/**
 * execute - executes a command
 * @args: arguments
 *
 * Return: 1 on success
*/
int execute(char **args)
{
	pid_t pid;
	int status;

	if (access(args[0], F_OK) == -1)
	{
		perror("Command not found");
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execute error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Forking error");
		return (1);
	}
	else
	{
		waitpid(-1, &status, 0);
		return (1);
	}
	return (1);
}
