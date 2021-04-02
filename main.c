#include "shell.h"

int main(int argc, char *argv[5],char *env[])
{
	int id;
	char *buffer;
	size_t bufsize = 0;
	char *token;
	char progpath[20];
	char *path = "/bin/";

	(void)argc;
	(void)env;

	while (1)
	{
		signal(SIGINT, ctrlc);
		write(1, "$ ", 2);

		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		rm_last_char_if(buffer);

		if(strcmp(buffer, "exit") == 0)
		{
			break;
		}

		token = strtok(buffer, " ");

		fill_argv(token, argv);

/*		printf("%s argv[0], %s argv[1]", argv[0], argv[1]); test */

		_strcpy(progpath, path);
		_strcat(progpath, argv[0]);

		id = fork();

		if (id == 0)
 		{
 			execve(progpath, argv, env);
			fprintf(stderr, "Child process could not do execvp\n");
 		}
 		else
 		{
 			wait(NULL);
 			printf("Child exited\n");
 		}
	}
	free(buffer);
	return (0);
}
