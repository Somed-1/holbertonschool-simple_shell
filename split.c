#include "shell.h"

/**
 * split_line - splits the user input
 * @line: user input
 * Return: array of args
 */
char **split_line(char *line)
{
	char **tokens = NULL, *token = NULL;
	int buffer = BUF_SIZE, newBuffer = 0, position = 0;
	char **backup_tokens = NULL;

	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= buffer)
		{
			newBuffer = BUF_SIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);
				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * split_path - splits a string into tokens
 *
 * @line: string to be splitted
 *
 * Return: array of tokens
*/
char **split_path(char *line)
{
	int buffer = BUF_SIZE, newBuffer = 0, position = 0;
	char **tokens = NULL, *token = NULL;
	char **backup_tokens = NULL;

	tokens = malloc(buffer * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, ":");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buffer)
		{
			newBuffer = BUF_SIZE * 2;
			backup_tokens = tokens;
			tokens = _realloc(tokens, buffer, newBuffer * sizeof(char *));
			if (tokens == NULL)
			{
				free(backup_tokens);
				free(tokens);

				fprintf(stderr, "memory allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, ":");
	}

	tokens[position] = NULL;
	return (tokens);
}
