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
