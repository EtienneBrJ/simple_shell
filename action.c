#include "shell.h"

void rm_last_char_if(char *buffer)
{
	int length;

	length = _strlen(buffer);

	if ( buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0';
	}
}

void fill_argv(char *token, char *argv[])
{
	int i = 0;

	while(token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
}
