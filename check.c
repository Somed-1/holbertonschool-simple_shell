#include "shell.h"

/**
 * check_spaces - checks if user input contains only spaces
 * @line: user input
 * Return: 0 if input contains only spaces
 */
int check_spaces(char *line)
{
	int i = 0;
	int flag = 1;
	int len = 0;

	len = strlen(line);
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
		i++;

	if (i != len)
		flag = 0;
	return (flag);
}

char *check_path(char **args, char **av)
{
	char *path, *first;
	char **path_arr, path_env[1024];
	int i = 0;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = args[0];

		if ((access(path, F_OK)) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
			av[0], 1, args[0]);
			return ("Fail access");
		}
	}
	else
	{
		strcpy(path_env, getenv("PATH"));

		path_arr = split_path(path_env);

		while (path_arr[i])
		{
			first = _strcat("/", args[0]);
			path = _strcat(path_arr[i], first);

			if ((access(path, F_OK)) == -1)
			{
				free(path);
				free(first);
			}
			else
			{
				free(path_arr);
				free(first);

				return (path);
			}
			i++;
		}

			free(path_arr);
			fprintf(stderr, "%s: %d: %s: not found\n",
			av[0], 1, args[0]);
			return ("Fail access");
	}

	return (path);
}
