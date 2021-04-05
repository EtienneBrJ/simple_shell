#include "shell.h"

<<<<<<< HEAD
int main(int argc, char *argv[5], char **env)
{
	char *buffer;
	size_t bufsize;
	pid_t pid;
	ssize_t chars;
	char *delim = " \n";
	int status; 

	(void)argc;
	(void)env;

=======
int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t chars;
	char *delim = " \n";
	char *argv[5]; 
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
	
	buffer = NULL;
	bufsize = 0;
	if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		signal(SIGINT, ctrlc);
	while ((chars = getline(&buffer, &bufsize, stdin)))
	{
		if (chars == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO,"\n",1);
			free(buffer);
<<<<<<< HEAD
			exit(0);
=======
			exit(EXIT_SUCCESS);
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
		}

		/*rm_last_char_if(buffer);*/
 
 		if(_strcmp(buffer, "exit") == 0)
 		{
<<<<<<< HEAD
 			free(buffer);
			exit(EXIT_SUCCESS);
 		}
		
=======
			/*free_double_ptr(argv);*/
			free(buffer);
			exit(EXIT_SUCCESS);
 		}
		if(_strcmp(buffer, "env") == 0)
		{
			print_environment(environ);
		}
	 
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
		parseString(buffer, argv, delim);

	 	pid = fork();
	
		if (pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			parseString(buffer, argv, delim);
			argv[0] = _execute(argv);
		}
		else
		{
			wait(&status);
		}
		

		buffer = NULL;
		bufsize = 0;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		

		buffer = NULL;
		bufsize = 0;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		

	}
	if (chars == -1)
	{
		return (EXIT_FAILURE);
	}
<<<<<<< HEAD
	if (chars == -1)
	{
		return (EXIT_FAILURE);
	}
=======
>>>>>>> fe94cf9b4d25929ee79853f4d8d99c15dd0ee90d
	return (EXIT_SUCCESS);
}
