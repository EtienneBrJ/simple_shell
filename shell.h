#ifndef SHELL_H
#define SHELL_H

#define BUF_SIZE 256
#define PROMPT 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* main func */
void print_prompt();
void _execute(char *buffer, char **argv);
void path_tester(char **argv, char *buffer);

/* for signal */
void ctrlc(int i);

/* str func */ 
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strstr(char *haystack, char *needle);
char *strcpfullPath(char *fullpath, char *dir, char *command, int l, int n);

/* env */
char *_getenv(char *var_env_name);
void print_environment(char **environ);

/* count */
int count_word(char *buffer);
int count_directories(char *path);

/* fill 2D array*/
char **fill_argv(char *buffer);
char **fill_directories(char *firstCommand);

/* builtins */
int change_dir(char **argv);
char *_getline();
void close_shell(char **argv, char *buffer);

/* memory */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_double_ptr(char **double_point);
void free_all(char *buffer, char **argv);

/* printing func */
void _puts(char *str);
int _putchar(char c);

/* num func */
int _atoi(char *s);
int _isdigit(int c);
int _isnumber(char *s);

#endif
