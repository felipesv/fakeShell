#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* LIBRARIES */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/wait.h>

/* MACROS */
#define ARGUM_SIZE 1

/* FUNCTIONS */
int _putchar(char c);
char *_prompt(int status_iss, char *fileName);
void delete_newline(char **prompt);
void _execve(char *prompt, char *fileName, char **env);
int _strcmp(char *s1, char *s2);
int countSpace(char *prompt);
char *get_env_value(char *nameVar, char **env);
int lengthArray(char *array);
char *_strcat(char *dest, char *src);
char *get_env_value(char *nameVar, char **env);
char *env_split(char *path_value, char *command, char *fileName);


#endif /* SIMPLE_SHELL_H */
