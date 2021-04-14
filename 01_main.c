#include "shell.h"
/**
 * main - entry point simple_shell for Holberton School
 *
 * Return: 0 exit success
 */
int main(void)
{
	char *buffer, **argv;

	while (PROMPT)
	{
		print_prompt();
		signal(SIGINT, ctrlc);
		buffer = _getline();
		argv = fill_argv(buffer);
		if (argv == NULL)
		{
			free(buffer);
			continue;
		}
		if (_strcmp("env", argv[0]) == 0)
			print_environment(environ);

		if (_strcmp("exit", argv[0]) == 0)
			close_shell(argv, buffer);
		if (_strcmp("cd", argv[0]) == 0)
		{
			change_dir(argv);
			free_all(buffer, argv);
			continue;
		}
		_execute(buffer, argv);
	}
	return (EXIT_SUCCESS);
}

/**
 * _execute - for the program to execute
 * @buffer: pointer
 * @argv: command line
 */
void _execute(char *buffer, char **argv)
{
	int status;

	pid_t pid = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork()");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		path_tester(argv, buffer);
	else
	{
		wait(&status);
		free(buffer);
		free_double_ptr(argv);
	}
}
/**
 * path_tester - test path
 * @argv: command line
 * @buffer: pointer
 */
void path_tester(char **argv, char *buffer)
{
	struct stat st;
	char **directories;
	int i = 0;

	directories = fill_directories(argv[0]);
	while (directories[i])
	{
		if (stat(directories[i], &st) == 0)
			execve(directories[i], argv, NULL);
		i++;
	}
	if (stat(argv[0], &st) == 0)
		execve(argv[0], argv, NULL);
	/* si on arrive ici c'est que lac commande existe pas*/
	/*il faudra voir pour print error comme /bin/sh*/
	perror(argv[0]);

	free(buffer);
	free_double_ptr(argv);
	free_double_ptr(directories);
	exit(EXIT_SUCCESS);
}

/**
 * print_prompt - print prompt
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

