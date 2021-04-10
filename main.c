#include "shell.h"

int main(void)
{
	char *buffer, **argv;
	
	pid_t pid; 
	int prompt = 1, status;
	
	/*buffer = NULL;*/
	
	
	while (prompt)
	{
		/*buffer = NULL;*/
		

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		signal(SIGINT, ctrlc);
		buffer = malloc(sizeof(char) * 256);
		_getline(buffer);

		argv = fill_argv(buffer);

		if (argv == NULL)
			continue;

		if (_strcmp("exit", argv[0]) == 0)
			close_shell(argv, buffer);
	
		if (_strcmp("env", argv[0]) == 0)
			print_environment(environ);
	    
		pid = fork();

	    if (pid == 0)
			path_tester(argv, buffer);	
		else
		{
			wait(&status);
			free(buffer);
			free_double_ptr(argv);
		}
	}
	return (EXIT_SUCCESS);	
}		


void path_tester(char **argv, char *buffer)
{
	struct stat st;
	char **directories;
	struct stat st2;
	int i = 0;

	directories = fill_directories(argv[0]);
	while (directories[i])
	{
		if (stat(directories[i], &st2) == 0)
			execve(directories[i], argv, NULL);
		i++;
	}
	if (stat(argv[0], &st) == 0)
		execve(argv[0], argv, NULL);
    /* si on arrive ici c'est que lac commande existe pas*/
	/*il faudra voir pour print error comme /bin/sh*/

	perror(argv[0]);


	free(buffer);
	free_double_ptr(argv);
	free_double_ptr(directories);
	exit(EXIT_SUCCESS);
}


