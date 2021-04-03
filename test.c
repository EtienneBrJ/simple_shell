#include "shell.h"

int main(int argc, char *argv[5],char *env[])
{
	char *buffer;
	size_t bufsize = 0;
	char *token;

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

/*		rm_last_char_if(buffer);
 *
 *		if(strcmp(buffer, "exit") == 0)
 *		{
 *			break;
 *		}
 *
 */		token = strtok(buffer, " \n");

		fill_argv(token, argv);

		_execute(argv);

	}
	free(buffer);
	return (0);
}
