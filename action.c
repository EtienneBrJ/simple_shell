#include "shell.h"
#include <stdio.h> 
char *_getenv(char *var_env_name)
{
	extern char **environ;
	int i = 0;

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

void *_which(char *command_name)
{
	char *env_name = "PATH";
	struct stat st;
	environment *absolute_path;

	if (command_name == NULL)
		exit(EXIT_FAILURE);

	if (stat(command_name, &st) != 0)
	{
		absolute_path = _parsingenv(env_name);
		if (stat(absolute_path, &st) == 0)
			return (absolute_path);
	}
	else
	 	return (command_name);
	return (NULL);
}


