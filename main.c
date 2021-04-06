#include "shell.h"

int main(void)
{
	char *buffer;
	size_t bufsize;
	char *delim = " \n\t\r\f\v";
	char *argv[10]; 
	int prompt = 1;

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
			/*free(buffer);*/
			break;
		}
		/*rm_last_char_if(buffer);*/
		
 		if(_strcmp(buffer, "exit") == 0)
 		{
			 break;
			/*free(buffer);*/
			/*exit(EXIT_SUCCESS);*/
 		}
		if(_strcmp(buffer, "env") == 0)
		{
			/*free(buffer);*/
			/*free_double_ptr(argv);*/
			print_environment(environ);
		}
	 	/*argv = _calloc(8, sizeof(char));*/
		if (argv == NULL)
			break;

		parseString(buffer, argv, delim);
		if (argv[0] == NULL)
			continue;
		else
			_execute(argv);
		
		

	}
	free(buffer);
	return (0);
}

