#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
 * _realloc - realloc for array of args
 * @ptr: pointer to array
 * @old_size: old size
 * @new_size: new size
 * Return: a pointer to the allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	char *ptr1;
	unsigned int i;

	ptr1 = (char *)ptr;
	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	s = malloc((new_size) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			s[i] = ptr1[i];
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			s[i] = ptr1[i];
	}
	free(ptr1);
	return (s);
}
