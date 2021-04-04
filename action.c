#include "shell.h"
#include <stdio.h>
char *_getenv(char *var_env_name)
{
	extern char **environ;
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env_name) != NULL)
			return (environ[i]);
		i++;
	}
	return (NULL);
}

void _execute(char *argv[])
{
	pid_t pid;
	char *command_to_execute;

	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		argv[0] = command_to_execute;

	pid = fork();
	if (pid == 0)
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	wait(NULL);
}

char *_which(char *command_name)
{
<<<<<<< HEAD
	char *absolute_path = "";
	char *path;
	char *list_path[5];
	int i = 1;
	struct stat st;
	extern char **environ;
	int jackline;
	char *delimiter = "=:";
=======
	char *absolute_path;
	char *path;
	char *list_path[10];
	int i = 1;
	struct stat st;
	extern char **environ;
	int size_str;
	char *delimiter = "=:";
	
>>>>>>> 930745ea5b475bf6941d6ef15bae2250a2bdf3c0

	if (command_name == NULL)
		exit(EXIT_FAILURE);

	if (stat(command_name, &st) != 0)
	{
		path = _getenv("PATH");
		if (path == NULL)
		{
			perror("Invalid path");
			return (NULL);
		}
<<<<<<< HEAD
		/*parseString(path, list_path, delimiter)*/

		list_path[0] = strtok(path, delimiter);
		list_path[1] = "";
		printf("test : %s", list_path[0]);
		while (list_path[i])
		{
			printf("PATH[1] %s", list_path[1]);
			list_path[i] = strtok(NULL, delimiter);

			jackline = _strlen(list_path[i]);
			if (list_path[i][jackline - 1] != '/')
			{
				list_path[i] = str_concat(list_path[i], "/");
			}

			str_concat(absolute_path, list_path[i]);
			str_concat(absolute_path, command_name);

			if (stat(absolute_path, &st) == 0)
				return (absolute_path);
=======

		parseString(path, list_path, delimiter);

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
>>>>>>> 930745ea5b475bf6941d6ef15bae2250a2bdf3c0
			i++;
		}
	}
	else
<<<<<<< HEAD
		return (command_name);
	return (NULL);
}
=======
	{
		 return (command_name);
	}
	return (NULL);
}
>>>>>>> 930745ea5b475bf6941d6ef15bae2250a2bdf3c0
