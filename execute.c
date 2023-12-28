#include "shell.h"

/**
 * execute - executes a command
 * @args: arguments
 * @av: array of args
 * Return: 1 on success
*/
int execute(char **args, char **av)
{
	pid_t pid;
	int status = 0;
	char *path = check_path(args, av);

	if (strcmp(path, "Fail access") == 0)
	{
		exit_status = 127;
		return (1);
	}
	else
	{
		pid = fork();
	}
	if (pid == 0)
	{
		execute_child(path, args);
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
	}

	return (1);
}

/**
 * execute_child - executes the command in the child process
 *
 * @path: the path to the command
 * @args: the arguments to the command
 *
 * Return: void
 */
void execute_child(char *path, char **args)
{
	if (execve(path, args, environ) == -1)
	{
		perror("Execute error");
		exit(EXIT_FAILURE);
	}
}
