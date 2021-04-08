#include "shell.h"
#include <stdio.h>

char **fill_argv(char *buffer) /* remplit argv avec les commandes passées dans le buffer*/
{                              /*ex : argv[0] = ls, argv[1] = -l, argv[2] = /tmp .. */
	char *delim = " \n\t\r\f\v";
	char **conteneur;
	char *token;
	int taille;
	int i = 0;
	
	/*remplace \n mis par getline par null*/
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

char *strcpfullPath(char *fullpath, char *dir, char *command, int l, int n) 
/* mets dans fullpath : le directory, le slash et la commande pour pouvoir tester stat */
{	int i, j;

	for (i = 0; dir[i] != '\0' && i < l; i++)
		fullpath[i] = dir[i];
	
	fullpath[i] = '/';
	i++;

	for (j = 0; command[j] != '\0' && j < n; i++, j++)
		fullpath[i] = command[j];
	fullpath[i] = '\0';

	return (fullpath);
}

/**
 *_strncpy - copy the string pointed by src
 *@src: source
 *@dest: destination
 *@n: int
 *Return: the pointer to the dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 *_strlen - returns the length of a string
 *@s: string
 *Return: the length of a string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * *_strstr - find the first occurence of a substring
 *@haystack: string
 *@needle: string
 *Return: NULL or the begining of the located substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;

	if (needle[0] == '\0')
	{
		return (haystack + i);
	}
	while (haystack[i] != '\0')
	{
		j = 0;

		while (needle[j] == haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
			{
				return (haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * *str_concat - concatenates two strings
 *@s1: string
 *@s2: string
 *Return: null on failure, pointer to dest
 */
char *str_concat(char *s1, char *s2)
{
	int s1len = 0;
	int s2len = 0;
	int i;
	char *dest;

	if (s1 != NULL)
	{
		while (s1[s1len] != '\0')
		{
			s1len++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[s2len] != '\0')
		{
			s2len++;
		}
	}
	dest = malloc((s1len + s2len + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < s1len; i++)
	{
		dest[i] = s1[i];
	}
	for (i = 0; i < s2len; i++)
	{
		dest[i + s1len] = s2[i];
	}
	dest[s1len + s2len] = '\0';
	return (dest);
}
/**
 *_strcmp - compare two string
 *@s1: string
 *@s2: string
 *Return: 0 if same return else
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
