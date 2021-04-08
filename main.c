#include "shell.h"

int main(void)
{
	char *buffer, **argv;
	size_t bufsize;
	pid_t pid; 
	int prompt = 1, status;
	
	buffer = NULL;
	bufsize = 0;
	
	while (prompt)
	{
		buffer = NULL;
		bufsize = 0;

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		signal(SIGINT, ctrlc);

		if (getline(&buffer, &bufsize, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			break;
		}
		
		argv = fill_argv(buffer);

		if (argv == NULL)
		{
			free(argv);
			free(buffer);
			continue;
		}
		
		if (_strcmp("exit", argv[0]) == 0)
			close_shell(argv, buffer);
	
		if (_strcmp("env", argv[0]) == 0)
			print_environment(environ);
	    
		pid = fork();

	    if (pid == 0)
			_execute(argv, buffer);	
		else
		{
			wait(&status);
			free(buffer);
			free_double_ptr(argv);
		}
	}
	return (EXIT_SUCCESS);	
}		

void _execute(char **argv, char *buffer)
{
	struct stat st;

	if (stat(argv[0], &st) == 0)
		execve(argv[0], argv, NULL);
	
	else
		path_tester(argv, buffer); /* va tester les path pour savoir si une commande existe */
}

void path_tester(char **argv, char *buffer)
{
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
    /* si on arrive ici c'est que lac commande existe pas*/
	
	perror(argv[0]);

	free(buffer);
	free_double_ptr(argv);
	
	free_double_ptr(directories);
	exit(EXIT_SUCCESS);
}


