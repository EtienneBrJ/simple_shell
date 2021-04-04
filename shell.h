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

typedef struct environment
{
	char *name;
	char *value;
	environment *next;
} env_l;


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
env_l *_parsingenv(char *env_name);
char *_strdup(char *str);
env_l *add_node_end(env_l **head, char *name, char *value);
int _strcmp(char *s1, char *s2);

#endif
