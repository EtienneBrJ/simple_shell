#include "shell.h"

/**
 * strtow - split strings into array of string
 * @str: string to split
 *
 * Return: char array
 */

char **strtow(char *str)
{
	char **tab;
	int cw = count_word(str);
	int i = 0;
	int j = 0;
	int n;

	if (str == 0 || cw == 0 || !str)
		return (0);

	tab = malloc(sizeof(char *) * (cw + 1));
	if (!tab)
		return (0);

	while (i < cw)
	{
		while (_checkspace(str, j) == 0 && str[j])
			j++;
		n = 0;
		while (_checkspace(str, j + n) == 1 && str[j + n])
			n++;
		tab[i] = _strndup(&str[j], n);
		j += n;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/**
 * _checkspace - check string for space
 * @str: string
 * @i: string index
 * Return: 0 for space else 1
 */
int _checkspace(char *str, int i)
{
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == ':')
		return (0);
	return (1);
}

/**
 * _strndup - duplicate string
 * @str: string to duplicate
 * @n: index
 * Return: pointer to duplicated string or 0 if str is null or fail
 */

char *_strndup(char *str, int n)
{
	char *dest;
	int i = 0;

	dest = malloc(sizeof(char) * n + 1);
	if (!dest)
		return (0);

	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

