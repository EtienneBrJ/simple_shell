#include "shell.h"
/**
 * main - entry point simple_shell for Holberton School
 *
 * Return: 0 exit success
 */
int main(void)
{
	char *buffer, **argv;
	int cont = 0;


	while (PROMPT)
	{
		cont++;
		print_prompt();
		signal(SIGINT, ctrlc);
		buffer = _getline();
		argv = fill_argv(buffer);
		if (argv == NULL)
		{
			free(buffer);
			continue; }
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
		_execute(buffer, argv, cont);
	}
	return (EXIT_SUCCESS);
}

/**
 * _execute - for the program to execute
 * @buffer: pointer
 * @argv: command line
 * @cont: cont
 */
void _execute(char *buffer, char **argv, int cont)
{
	int status;
	pid_t pid = 0;
	(void)cont;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork()");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		path_tester(argv, buffer, cont);
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
 * @cont: cont
 */
void path_tester(char **argv, char *buffer, int cont)
{
	struct stat st;
	char **directories;
	int i = 0;
	(void)cont;

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
	write(2, "./hsh: ", 7);
	print_number(cont);
	write(2, ": ", 2);
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": not found\n", 12);

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
/**
 * print_number - print number
 * @n: int
 */
void print_number(int n)
{
	char ni = NULL;

	if (n > 9)
	{
		print_number(n / 10);
		ni = ('0' + (n % 10));
		write(2, &ni, 1);
	}
	else
	{
		ni = '0' + n;
		write(2, &ni, 1);
	}
}
