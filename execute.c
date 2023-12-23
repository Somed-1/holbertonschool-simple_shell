#include "shell.h"

/**
 * execute - executes a command
 * @args: arguments
 *
 * Return: 1 on success
*/
int execute(char **args, char **av)
{
	pid_t pid;
	int status;
	char *path;

	path = check_path(args, av);

	if (strcmp(path, "Fail access") == 0)
	{
		free(path);
		return (1);
	}
	else
	{
		pid = fork();
	}
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
		free(path);
		perror("Forking error");
		return (1);
	}
	else
	{
		waitpid(-1, &status, 0);

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);

		if (args[0][0] != '/' && args[0][0] != '.')
			free(path);

		return (1);
	}
	return (1);
}
