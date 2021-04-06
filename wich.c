#include "shell.h"

char *_which(char *command_name)
{

	char *absolute_path = "", *path, *pathcp = "", *delimiter = "=:";
    char **list_path = NULL;
	struct stat st;
	int i = 0;
	
    if (command_name == NULL)
		return (NULL);

	if (stat(command_name, &st) != 0)
	{
		path = _getenv("PATH");
		if (path == NULL)
		{
			perror("Invalid path");
			return (NULL);
		}
		pathcp = mallocNstrncpy(pathcp, path); 
        list_path = mallocNparse(pathcp, list_path, delimiter);
		free(pathcp);
		while (list_path[i])
		{
			absolute_path = put_in_Form(list_path, command_name, i);
			if (stat(absolute_path, &st) == 0)
			{
				free_double_ptr(list_path);
				return (absolute_path);
			}
			i++;
		}
		free_double_ptr(list_path);
	}
	else
	{
		 return (command_name);
	}
	return (NULL);
}


char *mallocNstrncpy(char *pathcp, char *path)
{
    int n;

    n = _strlen(path);
    pathcp = _calloc(n, sizeof(char));
    _strncpy(pathcp, path, n);
	return(pathcp);
}

char **mallocNparse(char *pathcp, char **list_path, char *delimiter)
{
    int n;

    n = _strlen(pathcp);
    list_path = _calloc(n, sizeof(char));
	parseString(pathcp, list_path, delimiter);
	return (list_path);
}

char *put_in_Form(char **list_path, char *command_name, int index)
{
	char *absolute_path;
	int size_str;

			size_str = _strlen(list_path[index]);
			if (list_path[index][size_str - 1] != '/')
			{
				list_path[index] = str_concat(list_path[index], "/");
			}
			absolute_path = "";
			absolute_path = str_concat(absolute_path, list_path[index]);
			absolute_path = str_concat(absolute_path, command_name);
			
						
			return (absolute_path);
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size bytes
 * Return: pointer
 **/

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