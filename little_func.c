#include "shell.h"

int count_word(char *buffer)
{
	int i = 0, nb_mot = 0;

	while (buffer[i])
	{
		if ((buffer[i] != ' ' && buffer[i + 1] == ' ')
		|| (buffer[i] != ' ' && buffer[i + 1] == '\0'))
				nb_mot++;
		i++;
	}
	return (nb_mot);

}

int count_directories(char *path)
{
	int i;
	int nb_dir = 0;

	for (i = 0; path[i]; i++)
		if ((path[i] != ':' && path[i + 1] == ':')
		|| (path[i] != ':' && path[i + 1] == '\0'))
				nb_dir++;
	return (nb_dir);
}

char *_getenv(char *var_env_name)
{
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env_name) != NULL && environ[i][0] == var_env_name[0])
			return (environ[i]);
		i++;
	}
	return (NULL);
}

void print_environment(char **environ)
{
    int i, length;

    i = 0;

    while (environ[i])
    {
        length = _strlen(environ[i]);

        write(STDOUT_FILENO, environ[i], length);
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

void ctrlc(int i)
{
	i = i;
	write(1, "\n$ ", 3);
}

void close_shell(char **argv, char *buffer)
{
	free(buffer);
	free_double_ptr(argv);
	exit (EXIT_SUCCESS);
}

void free_double_ptr(char **double_point)
{
	int i = 0;

	if (double_point == NULL)
		return;

	while (double_point[i])
	{
		free(double_point[i]);
		++i;
	}

	/*if (double_point[i] == NULL)
		free(double_point[i]);*/

	free(double_point);
}

void argv_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}





