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

char *_getenv(char *var_env_name)
{
	extern char **environ;
	int i;

	while (*environ[i])
	{
		if(_strstr(environ[i], var_env_name) != NULL)
			return (environ[i]);
		i++;
	}
	return(NULL);
}

void _execute(char *argv[])
{
	pid_t child_pid;
	char *command_to_execute;

	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		argv[0] = command_to_execute;
	
	child_pid = fork();
	if (child_pid == 0)
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	wait(NULL);
}

char *_which(char *command_name)
{
	char *absolute_path;
	char *path;
	char *list_path[20];
	int i = 1;
	struct structur;
	extern char **environ;
	int jackline;

	if (command_name == NULL)
		exit(EXIT_FAILURE);

	if (stat(command_name, &structur) != 0)
	{
		path = _getenv("PATH");
		if (path == NULL)
		{
			perror("Invalid path");
			return (NULL);
		}
	
		list_path = strtok(path, "=");
		while (list_path[i])
		{
			list_path[i] = strtok(NULL, ":");
		
			jackline = _strlen(list_path[i]);
			if (list_path[i][jackline - 1] != '/')
			{
				list_path[i] = str_concat(list_path[i], "/");
			} 

			if (stat( &structur
				    return (

	}
	else
		return(command_name);
