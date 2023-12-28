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

/* check.c */
int check_spaces(char *line);
char *check_path(char **args, char **av);
char *find_absolute_path(char **args, char **av);
char *find_relative_path(char **args, char **av, char *path_env);

/* split.c */
char **split_line(char *line);
char **split_path(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* utils.c */
char *_strcat(char *str1, char *str2);

/* execute.c */
int execute(char **args, char **av);
int execute_builtins(void);
void execute_child(char *path, char **args);
void execute_parent(char *path, char **args, int status);

/* builtins.c */
int check_exit(char **args);
int check_env(char **args);

#endif
