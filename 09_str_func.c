#include "shell.h"

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
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: -0 if s1 < s2, 0 if they're equal,
 * +0 if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * strcpfullPath - copy the full path
 * @fullpath: pointer to full path
 * @dir: point to directories
 * @command: command line
 * @l: lenght
 * @n: lenght
 * Return: full path
 */
char *strcpfullPath(char *fullpath, char *dir, char *command, int l, int n)
{
	int i, j;

	for (i = 0; dir[i] != '\0' && i < l; i++)
		fullpath[i] = dir[i];

	fullpath[i] = '/';
	i++;

	for (j = 0; command[j] != '\0' && j < n; i++, j++)
		fullpath[i] = command[j];
	fullpath[i] = '\0';

	return (fullpath);
}
