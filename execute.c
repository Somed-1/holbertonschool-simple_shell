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
	char *path;

	path = check_path(args);

	if (strcmp(path, "Fail access") == 0)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
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
