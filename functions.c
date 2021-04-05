#include "shell.h"

void ctrlc(int i)
{
	i = i;
	write(STDOUT_FILENO, "\n$ ", 3);
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

void parseString(char *buffer, char *argv[], char *delim)

{
	int i = 0;
    char *token;

    token = strtok(buffer, delim);

	while(token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
}