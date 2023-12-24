#include "shell.h"

#define EXIT_CMD "exit"

/**
 * check_exit - checks if the user typed exit
 *
 * @args: the arguments passed to the shell
 *
 * Return: 1 if the user typed exit, 0 otherwise
*/
int check_exit(char **args)
{
	if (strcmp(args[0], EXIT_CMD) == 0)
	{
		return (1);
	}

	return (0);
}
