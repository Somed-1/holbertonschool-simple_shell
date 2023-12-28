#include "shell.h"

char *find_absolute_path(char **args, char **av);
char *find_relative_path(char **args, char **av, char *path_env);

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

/**
 * *check_path - checks if the command is in the path
 *
 * @args: arguments
 * @av: arguments
 *
 * Return: path
*/
char *check_path(char **args, char **av)
{
	char *path;
	char *temp;
	char path_env[1024];

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = find_absolute_path(args, av);
	}
	else
	{
		temp = getenv("PATH");
		if (temp != NULL)
		{
			strcpy(path_env, temp);
		}
		else
		{
			fprintf(stderr, "%s:	%d:	%s:	not	found\n", av[0], 1, args[0]);
			return ("Fail	access");
		}

		path = find_relative_path(args, av, path_env);
	}

	return (path);
}

/**
 * *find_absolute_path - find the absolute path of a command
 *
 * @args: arguments
 * @av: arguments
 *
 * Return: absolute path
 */
char *find_absolute_path(char **args, char **av)
{
	char *path = args[0];

	if (access(path, F_OK) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", av[0], 1, args[0]);
		return ("Fail access");
	}

	return (path);
}

/**
 * *find_relative_path - find the relative path of a command
 *
 * @args: arguments
 * @av: arguments
 * @path_env: path environment
 *
 * Return: relative path
 */
char *find_relative_path(char **args, char **av, char *path_env)
{
	char **path_arr = split_path(path_env);
	char *path;
	char *first;
	int i = 0;

	while (path_arr[i])
	{
		first = _strcat("/", args[0]);
		path = _strcat(path_arr[i], first);

		if (access(path, F_OK) == -1)
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
	fprintf(stderr, "%s: %d: %s: not found\n", av[0], 1, args[0]);
	return ("Fail access");
}
