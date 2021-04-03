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
		write(1, "$ ", 2);

		signal(SIGINT, ctrlc);

		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			exit(EXIT_FAILURE);
		}

		write(1, "$ ", 2);

		rm_last_char_if(buffer);

		if(strcmp(buffer, "exit") == 0)
		{
			break;
		}

		token = strtok(buffer, " ");

		fill_argv(token, argv);

/*		printf("%s argv[0], %s argv[1]", argv[0], argv[1]); test */

/*		_strcpy(progpath, path);*/
		_strcpy(progpath, argv[0]);
/*		printf("progpath before fork : %s\n", progpath);*/
		id = fork();

		if (id == 0)
 		{
 			execve(progpath, argv, env);
			fprintf(stderr, "Child process could not do execvp\n");
 		}
 		else
 		{
 			wait(NULL);
 		}
	}
	free(buffer);
	return (0);
}
