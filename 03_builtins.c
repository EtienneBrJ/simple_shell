#include "shell.h"
/**
 * _getline - reads an entire line from stream
 * Return: returns buffer
 */
char *_getline()
{
	char c = '\0', *buffer;
	int i = 0, rd, bufferSize = BUF_SIZE;

	buffer = malloc(sizeof(char) * BUF_SIZE + 1);

	while (c != '\n' && c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);

		if (rd == 0)
		{
			c = EOF;
			write(STDIN_FILENO, "\n", 1);
			free(buffer);
			exit(0);
		}

		if (i >= bufferSize - 1)
		{
			buffer = _realloc(buffer, bufferSize, sizeof(char) * (i + 2));
			bufferSize = i + 2;
		}
		buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';

	return (buffer);
}
/**
 * change_dir - change directory with cd command
 * @argv: command line
 * Return: returns 0, or -1 if fail
 */
int change_dir(char **argv)
{
	int a, b;
	char *home;

	home = _getenv("HOME");
	home = strtok(home, "=");
	home = strtok(NULL, "=");
	if (argv[1] == NULL)
	{
		a = chdir(home);
		if (a < 0)
			return (-1);
		return (0);
	}
	if (_strcmp(argv[1], "~") == 0)
	{
		b = chdir(home);
		if (b < 0)
			return (-1);
		return (0);
	}
	else
	{
		b = chdir(argv[1]);
		if (b < 0)
			perror("Path not good");
		return (-1);
		return (0);
	}
	return (0);
}
/**
 * close_shell - close the shell and free memory
 * @argv: command line
 * @buffer: buffer
 * @cont: cont
 */
void close_shell(char **argv, char *buffer, int cont)
{
	int n = 0;
	(void)cont;
	if (argv[1] == NULL)
	{
		free_exit(buffer, argv);
		exit(0);
	}
	if (_strcmp("1000", argv[1]) == 0)
	{
		free_exit(buffer, argv);
		exit(232);
	}
	if (_isnumber(argv[1]))
	{
		n = _atoi(argv[1]);
		free_exit(buffer, argv);
		exit(n);
	}
	else if (argv[1])
	{
		write(2, "./hsh: ", 7);
		print_number(cont);
		write(2, ": ", 2);
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": Illegal number", 16);
		write(2, ": ", 2);
		write(2, argv[1], _strlen(argv[1]));
		write(2, "\n", 1);
		free_exit(buffer, argv);
		exit(2);
	}
	else
	{
		free_exit(buffer, argv);
		exit(EXIT_SUCCESS);
	}

}

