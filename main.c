#include "shell.h"

int main(int argc, char **argv,char **env)
{
	char *buffer;
	size_t bufsize;
	ssize_t chars;
	char *delim = " \n";
	
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

		rm_last_char_if(buffer);
 
 		if(strcmp(buffer, "exit") == 0)
 		{
 			free(buffer);
			exit(EXIT_SUCCESS);
 		}
		else if (argv[0] == NULL)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
 
		parseString(buffer, argv, delim);

		_execute(argv);

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
