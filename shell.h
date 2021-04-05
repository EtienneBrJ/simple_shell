#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void fill_argv(char *token, char *argv[]);
void rm_last_char_if(char *buffer);
void ctrlc(int i);
char *_which(char *command_name);
char *_strstr(char *haystack, char *needle);
char *str_concat(char *s1, char *s2);
void _execute(char *argv[]);
char *_getenv(char *var_env_name);
void parseString(char *buffer, char *argv[], char *delim);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void free_double_ptr(char **double_point);
#endif
