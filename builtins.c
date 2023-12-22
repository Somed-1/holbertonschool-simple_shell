#include "shell.h"

#define EXIT_CMD "exit"

int check_exit(char *args)
{
	if (strcmp(args, EXIT_CMD) == 0)
		return (0);

	return (1);
}
