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
			break;
		}
		/*rm_last_char_if(buffer);  ca fou la merde*/
 		if(_strcmp(buffer, "exit") == 0)
 		{
			 
			free(buffer);
			exit(EXIT_SUCCESS);
 		}
		if(_strcmp(buffer, "env") == 0)
		{
			print_environment(environ);
		}
	 	/*argv = _calloc(50, sizeof(char));*/
	    parseString(buffer, argv, delim);

		if (argv[0] == NULL)
			continue;
		else
			_execute(argv);
		
		

	}
	free(buffer);
	return (0);
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
		free(argv[0]); 
		exit(0);

	}

	else
	{
		wait(&status);
		/*free(command_to_execute);*/
	}
}

