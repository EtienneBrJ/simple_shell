#include "shell.h"

char *_getenv(char *var_env_name)
{
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env_name) != NULL && environ[i][0] == var_env_name[0])
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

	if (argv == NULL || argv[0] == NULL)
		return;

	command_to_execute = _which(argv[0]);
	if (command_to_execute != NULL)
		argv[0] = command_to_execute;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
		}
		exit(0);
	}

	else
		wait(&status);
	free(command_to_execute);
}
