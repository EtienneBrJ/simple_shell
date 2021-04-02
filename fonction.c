#include "shell.h"
/**
 * *_strcpy - copy the string pointed by src
 *@src: source to copy
 *@dest: char pointer
 *Return: the pointer to the dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != 0 ; i++)
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
	int char_end_src;/*array nuber with value '\0' in src*/
	int i;
/*loocking for '\0' in dst*/
	{
		for (i = 0 ; dest[i] != '\0' ; i++)
		{
		}
		for (char_end_src = 0 ; src[char_end_src] != '\0' ; char_end_src++)
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
