#include "shell.h"
#include <stdio.h>

char **fill_argv(char *buffer) /* remplit argv avec les commandes passées dans le buffer*/
{                              /*ex : argv[0] = ls, argv[1] = -l, argv[2] = /tmp .. */
	char *delim = " \n\t\r\f\v";
	char **conteneur;
	char *token;
	int taille;
	int i = 0;
	
	
	buffer[_strlen(buffer) - 1] = '\0';
	taille = count_word(buffer);
	if (taille == 0 )
		return (NULL);
			
    conteneur = malloc((taille + 1) * sizeof(char*));
	if (!conteneur)
		return (NULL);
	
	
	token = strtok(buffer, delim);
	while (token)
	{
		conteneur[i] = malloc((_strlen(token) + 1 ) * sizeof(char));
		if (!conteneur[i])
		{
			free_double_ptr(conteneur);
			return (NULL);
		}
		_strncpy(conteneur[i], token, _strlen(token) + 1);
		token = strtok(NULL, delim);
		i++;
	}
	
	conteneur[i] = NULL;
	
	return (conteneur);
}

		
char **fill_directories(char *firstCommand) 
/* remplit directories avec les différents chemin du PATH qu'on doit tester*/
/*ex : directories[0] = /usr/bin, argv[1] = /usr/sbin, argv[2] = /usr/games .. */
{ 
	char **directories, *path, *dir;
	int nb_dir, i = 0;
	int dir_length, command_length;

	path = _getenv("PATH");
	nb_dir = count_directories(path);
	directories = malloc((sizeof(char*)) * (nb_dir + 2));
	if (directories == NULL)
		return (NULL);
		
	dir = strtok(path, "=");

	while (dir != NULL)
	{
		dir_length = _strlen(dir);
		command_length = _strlen(firstCommand);
		directories[i] = malloc(sizeof(char*) * (dir_length + command_length + 2));
		if (directories[i] == NULL)
		{
			free_double_ptr(directories);
			return (NULL);
		}
			strcpfullPath(directories[i], dir, firstCommand,
			dir_length, command_length);
			i++;
		dir = strtok(NULL, ":");
	}
	directories[i] = NULL;
	return (directories);
}



/**
 * _puts - Print a sting, followed by a new line
 * @str: Chars to output
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

void ctrlc(int i)
{
	i = i;
	write(1, "\n$ ", 3);
}
