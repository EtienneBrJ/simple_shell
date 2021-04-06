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

		if (command_to_execute == NULL)
		{
			exit(EXIT_SUCCESS);
		}
		if (execve(argv[0], argv, NULL) == -1)
		{

			perror(argv[0]);
			free(command_to_execute);
			/*free_double_ptr(argv);*/
			exit(0);
		}
	}

	else
		wait(&status);
	/*free(command_to_execute);*/
}
