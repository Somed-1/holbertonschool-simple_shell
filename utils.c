#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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

/**
 * *_strcat - concatenates two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer to the resulting string
*/
char *_strcat(char *s1, char *s2)
{
	char *s;
	unsigned int i;
	unsigned int j;
	unsigned int k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		continue;

	for (j = 0; s2[j] != '\0'; j++)
		continue;

	j = j + 1;

	s = malloc((i + j) * sizeof(char));
	if (s == NULL)
		return (0);

	for (k = 0; k < (i + j) ; k++)
	{
		if (k < i)
			s[k] = s1[k];
		if (k >= i)
			s[k] = s2[k - i];
	}
	return (s);
}
