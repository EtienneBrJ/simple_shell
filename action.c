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

char *_execute(char *argv[])
{
<<<<<<< HEAD
	char *command_to_execute;
	
	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		return (command_to_execute);
	return (command_to_execute);	
=======
	int status;
	pid_t pid;
	char *command_to_execute;
	
	
	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		argv[0] = command_to_execute;

	pid = fork();
	
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}	
	else
	waitpid(pid, &status, WUNTRACED);
	
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
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
	int length;



	if (command_name == NULL)
		exit(EXIT_FAILURE);

	if (stat(command_name, &st) != 0)
	{
		path = _getenv("PATH");
<<<<<<< HEAD
		printf("env %s\n", path);
=======
		
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
		if (path == NULL)
		{
			perror("Invalid path");
			return (NULL);
		}
		length = _strlen(path);
		pathcp = malloc((sizeof(char) * length) + 1);
		if(pathcp == NULL)
			return(NULL);
		_strncpy(pathcp, path, length);
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
				free(pathcp);
				return (absolute_path);
      }
			i++;
		
		free(absolute_path);	
		}
	}
	else
	{
		 return (command_name);
	}
	return (NULL);
}
