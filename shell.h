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

/**
 * struct list_s - singly linked list
 * @index: integer
 * @next: points to the next node
 * @str: point to var env
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	unsigned int index;
	char *str;
	struct list_s *next;
} list_t;


/* linked list for env */
list_t *add_node_end(list_t **head, char *str,  unsigned int index);
size_t print_list(list_t *h);
void free_list(list_t *head);
list_t *init_list_env(list_t *h);
size_t listint_len(list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);

/* main func */
void print_prompt(void);
void _execute(char *buffer, char **argv, int cont);
void path_tester(char **argv, char *buffer, int cont);

/* for signal */
void ctrlc(int i);

/* str func */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strstr(char *haystack, char *needle);
char *strcpfullPath(char *fullpath, char *dir, char *command, int l, int n);
char *_strdup(char *str);

/* env */
char *_getenv(char *var_env);
void print_environment(void);
void unset_env(char *buffer, char **argv, list_t *head);

void set_env(char *buffer, char **argv, list_t *head);

/* count */
int count_word(char *buffer);
int count_directories(char *path);

/* fill 2D array*/
char **fill_argv(char *buffer);
char **fill_directories(char *firstCommand);

/* builtins */
int change_dir(char **argv);
char *_getline();
void close_shell(char **argv, char *buffer, int cont);

/* memory */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_double_ptr(char **double_point);
void free_exit(char *buffer, char **argv);
void free_all(char *buffer, char **argv);

/* printing func */
void _puts(char *str);
int _putchar(char c);

/* num func */
int _atoi(char *s);
int _isdigit(int c);
int _isnumber(char *s);


void print_number(int n);


#endif
