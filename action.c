#include "shell.h"
#include <stdio.h>
char *_getenv(char *var_env_name)
{
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env_name) != NULL)
			return (environ[i]);
		i++;
	}
	return (NULL);
}

void _execute(char **argv)
{
	int status;
	pid_t pid;
	char *command_to_execute;

	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		argv[0] = command_to_execute;

	pid = fork();

	if (pid == 0)
	{

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			/*free(command_to_execute);*/
			/*free_double_ptr(argv);*/
			exit(0);
		}
	}

	else
		wait(&status);
	/*free(command_to_execute);*/
}

char *_which(char *command_name)
{
	char *absolute_path;
	char *path;
	char *pathcp;
	char *list_path[10];
	int i = 1;
	struct stat st;
	int size_str;
	char *delimiter = "=:";
	int length = 0;

	if (command_name == NULL)
	{
		return (NULL);
	}
	if (stat(command_name, &st) != 0)
	{
		path = _getenv("PATH");

		if (path == NULL)
		{
			perror("Invalid path");
			return (NULL);
		}
		length = _strlen(path);

		pathcp = malloc((sizeof(char) * length) + 1);
		if (pathcp == NULL)
			return (NULL);

		_strncpy(pathcp, path, length);

	/*	list_path = malloc(sizeof(char) * length);*/
		if (list_path == NULL)
			return (NULL);
		parseString(pathcp, list_path, delimiter);

		while (list_path[i])
		{
			size_str = _strlen(list_path[i]);
			if (list_path[i][size_str - 1] != '/')
			{
				list_path[i] = str_concat(list_path[i], "/");
			}
			absolute_path = "";
			absolute_path = str_concat(absolute_path, list_path[i]);
			absolute_path = str_concat(absolute_path, command_name);

			if (stat(absolute_path, &st) == 0)
			{
				
				return (absolute_path);
			}
			i++;
		}
		
		/*free_double_ptr(list_path);*/
		free(pathcp);
	}
	else
	{
		return (command_name);
	}
	return (NULL);
}
