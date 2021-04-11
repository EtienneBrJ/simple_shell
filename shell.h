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

void ctrlc(int i);
void close_shell(char **argv, char *buffer);
void argv_null(char *buffer);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strstr(char *haystack, char *needle);

char *_getenv(char *var_env_name);
void print_environment(char **environ);

void path_tester(char **argv, char *buffer);

int count_word(char *buffer);
int count_directories(char *path);

char **fill_argv(char *buffer);
char **fill_directories(char *firstCommand);

char *strcpfullPath(char *fullpath, char *dir, char *command, int l, int n);

int change_dir(char **argv);

char *_getline(char *buffer);

void *_calloc(unsigned int nmemb, unsigned int size);
void *_recalloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_double_ptr(char **double_point);
#endif
