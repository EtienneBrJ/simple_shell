#include "shell.h"

#define BUF_SIZE 1024

int main(void)
{
	char *buffer, **argv;
	char *getdir, *dir, *to; 
	char buf[BUF_SIZE];

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
			continue;

		if (_strcmp("exit", argv[0]) == 0)
			close_shell(argv, buffer);
	
		if (_strcmp("env", argv[0]) == 0)
			print_environment(environ);

		if (_strcmp("cd", argv[0]) == 0)
		{
			getdir = getcwd(buf, sizeof(buf));
			dir = strcat(getdir, "/");
			to = strcat(dir, argv[1]);

			chdir(to);
			continue;
		}
	    
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
	int i = 0;

	directories = fill_directories(argv[0]);
	while (directories[i])
	{
		if (stat(directories[i], &st) == 0)
			execve(directories[i], argv, NULL);
		i++;
	}
    /* si on arrive ici c'est que lac commande existe pas*/
	/*il faudra voir pour print error comme /bin/sh*/

	if (stat(argv[0], &st) == 0)
		execve(argv[0], argv, NULL);

	if (_strcmp(argv[0], "^C") == 0)
		{
			free(buffer);
			free_double_ptr(argv);
			free_double_ptr(directories);
			exit(EXIT_SUCCESS);
		}

	write(STDERR_FILENO, ":-( command: not found\n", 24);


	free(buffer);
	free_double_ptr(argv);
	free_double_ptr(directories);
	exit(EXIT_SUCCESS);
}


