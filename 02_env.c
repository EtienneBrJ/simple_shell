#include "shell.h"
/**
 * _getenv - get the environment
 * @var_env: environment variable
 * Return: environ[i], or NULL
 */
char *_getenv(char *var_env)
{
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env) != NULL && environ[i][0] == var_env[0])
			return (environ[i]);
		i++;
	}
	return (NULL);
}
/**
 * print_environment - print environment
 * @environ: pointer of pointer to environ
 */
void print_environment(char **environ)
{
	int i, length;

	i = 0;

	while (environ[i])
	{
		length = _strlen(environ[i]);

		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * set_env - add a variable to the environment
 * @buffer: pointer to buffer
 * @argv: command line
 * @head: linkedlist of the environment
 */
void set_env(char *buffer, char **argv, list_t *head)
{
	if (argv[1] == NULL)
	{
		free(buffer);
		free_double_ptr(argv);
	}
	else if (argv[1] && argv[2])
	{
		puts("too many arguments");
		free(buffer);
		free_double_ptr(argv);
	}
	else
	{
		add_node_end(&head, argv[1], 0);
		free(buffer);
		free_double_ptr(argv);

	}
}
/**
 * unset_env - remove a variable to th environment (remove a node at index)
 * @buffer: buffer
 * @argv: command line
 * @head: linked list of the environment
 */
void unset_env(char *buffer, char **argv, list_t *head)
{
	list_t *tmp = head;
	size_t idx = 0;

	if (argv[1] == NULL)
	{
		free(buffer);
		free_double_ptr(argv);
	}
	else if (argv[1] && argv[2])
	{
		perror("too many arguments");
		free_double_ptr(argv);
	}
	else
	{
		while (tmp)
		{
			if (_strcmp(tmp->str, argv[1]) == 0)
			{
				delete_node_at_index(&head, idx);
				break;
			}
			tmp = tmp->next;
			idx++;
		}
		free(buffer);
		free_double_ptr(argv);
	}
}
