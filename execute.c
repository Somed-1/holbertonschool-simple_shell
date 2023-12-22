#include "shell.h"


int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Execute error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Forking error");
		return(1);
	}
	else
	{
		waitpid(-1, &status, 0);
		return (1);
	}
	return (1);
}
