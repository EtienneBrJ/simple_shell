#include "shell.h"
#include <stdio.h>


void parseString(char *buffer, char *argv[10], char *delim)

{
	int i = 0;
    char *token;

    token = strtok(buffer, delim);

	/*if (token == NULL)
	return (NULL);*/

	while(token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(token); 

}

void ctrlc(int i)
{
	i = i;
	write(1, "\n$ ", 3);
}


void rm_last_char_if(char *buffer)
{
	int length;

	length = _strlen(buffer);

	if ( buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0';
	}
}


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

void free_double_ptr(char **double_point)
{
	int i = 0;

	if (double_point == NULL)
		return;

	while (double_point[i])
	{
		free(double_point[i]);
		++i;
	}

	/*if (double_point[i] == NULL)
		free(double_point[i]);*/

	free(double_point);
}