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

		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		return (1);
	}
	return (1);
}
