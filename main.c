#include "shell.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	char **argv; 
	int prompt = 1;
	int status;
	pid_t pid;
	buffer = NULL;
	bufsize = 0;
	
	while (prompt)
	{
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

		pid = fork();

	    if (pid == 0)
			_execute(argv, buffer);	
		else
		{
			wait(&status);
			free(buffer);
			free_double_ptr(argv);
		}
		buffer = NULL;
		bufsize = 0;
		
    }
	return (EXIT_SUCCESS);	
}		

void _execute(char **argv, __attribute__((unused))char *buffer)
{
	struct stat st;

   /* printf("%s : dans execute\n", argv[0]);
	if (argv == NULL)
		argv_null(buffer);

	else if (_strcmp("exit", argv[0]))
		close_shell(argv, buffer);
	
	else if (_strcmp("env", argv[0]))
		print_environment(environ);
	
	else */
	if (stat(argv[0], &st) == 0)
		execve(argv[0], argv, NULL);
	
	else
		path_tester(argv, buffer); /* comme _which */
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

	/*commande pas trouvée: print error il faudra revoir*/

	write(STDERR_FILENO, ":-( command: not found\n", 24);


	free(buffer);
	free_double_ptr(argv);
	free_double_ptr(directories);
	exit(EXIT_SUCCESS);
}


