#include "shell.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	ssize_t chars;
	char *delim = " \n";
	char *argv[5]; 
	
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
 
 		if(_strcmp(buffer, "exit") == 0)
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
