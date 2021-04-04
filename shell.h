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
char *_strdup(char *str);
environment *add_node_end(environment **head, char *str, char *token);
int _strcmp(char *s1, char *s2);
environment _parsingenv(char *env_name)

#endif
