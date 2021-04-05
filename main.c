#include "shell.h"

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
			exit(0);
		}

		/*rm_last_char_if(buffer);*/
 
 		if(_strcmp(buffer, "exit") == 0)
 		{
 			free(buffer);
			exit(EXIT_SUCCESS);
 		}
		
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
		

	}
	if (chars == -1)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
