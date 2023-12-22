#include "shell.h"

#define EXIT_CMD "exit"

int check_exit(char **args)
{
	int i;

	if (args[2])
	{
		for (i = 0; args[i] != NULL; i++)
		{
			if (strcmp(args[i], EXIT_CMD) == 0)
			{
				exit_status = 2;
				return (1);
			}
		}
	}
	else
	{
		if (strcmp(args[0], EXIT_CMD) == 0)
		{
			exit_status = 0;
			return (1);
		}
	}

	return (0);
}
