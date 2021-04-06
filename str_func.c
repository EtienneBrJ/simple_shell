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
 * *_strcpy - copy the string pointed by src
 *@src: source to copy
 *@dest: char pointer
 *Return: the pointer to the dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *_strcat - concatenates two strings
 *@src: source
 *@dest: destination
 *Return: return a pointeur to tthe resulting string
 */
char *_strcat(char *dest, char *src)
{
	int char_end_src; /*array nuber with value '\0' in src*/
	int i;
	/*loocking for '\0' in dst*/
	{
		for (i = 0; dest[i] != '\0'; i++)
		{
		}
		for (char_end_src = 0; src[char_end_src] != '\0'; char_end_src++)
		/*add add src to dest*/
		{
			dest[i + char_end_src] = src[char_end_src];
		}
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
