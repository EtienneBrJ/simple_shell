#include "shell.h"

int main(int argc, char *argv[5],char *env[])
{
	int id;
	char *buffer;
	size_t bufsize = 0;
	char *token;
	char progpath[20];
	

	(void)argc;
	(void)env;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		signal(SIGINT, ctrlc);
		

		if (getline(&buffer, &bufsize, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1,"\n",1);
			break;
		}

		rm_last_char_if(buffer);

		if(strcmp(buffer, "exit") == 0)
		{
			break;
		}

		token = strtok(buffer, " ");

		fill_argv(token, argv);

		_execute(argv);

		_strcpy(progpath, argv[0]);
		
		id = fork();

		if (id == 0)
		{
 			if(execve(progpath, argv, NULL) == -1)
				fprintf(stderr, "Child process could not do execvp\n");
		}
 	       	wait(NULL);
 		printf("Child exited\n");
 		
	}
	free(buffer);
	return (0);
}
