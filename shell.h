#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 100
#define DELIM " \t\n"

int exit_status;
extern char **environ;

typedef struct builtin_n
{
	char *name_builtin;
	int (*func_builtin)(char **args);
} builtins_t;

/* check.c */
int check_spaces(char *line);
char *check_path(char **args, char **av);

/* split.c */
char **split_line(char *line);
char **split_path(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* utils.c */
char *_strcat(char *str1, char *str2);

/* execute.c */
int execute(char **args, char **av);
int execute_builtins(void);

/* builtins.c */
int check_exit(char **args);
int check_env(char **args);

#endif
