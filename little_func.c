#include "shell.h"

int count_word(char *buffer)  /* on compte les mots pour pouvoir malloc argv bien*/
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

int count_directories(char *path) /* on compte les directories pour pouvoir malloc directories correctement*/
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
		i++;
	}

	if (double_point[i] == NULL)
		free(double_point[i]);

	free(double_point);
}

void argv_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		s[i] = 0;
	return (s);
}

/**
 * _realloc - reallocates a memory using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes if the allocated space for ptr
 * @new_size: new size in bytes of the memory block
 *
 * Return: pointer to the new block
 **/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p_new;
	unsigned int i;
	char *ptr1;

	ptr1 = ptr;

	if (!ptr1)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	p_new = malloc(new_size);
	if (!p_new)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p_new[i] = ptr1[i];
	}
	free(ptr);
	return (p_new);
}



