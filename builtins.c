#include "shell.h"

#define EXIT_CMD "exit"

int check_exit(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], EXIT_CMD) == 0)
			return (1);
	}

	return (0);
}
