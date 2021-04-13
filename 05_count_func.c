#include "shell.h"
/**
 * count_word - count words
 * @buffer: pointer to buffer
 * Return: Nbr of word
 */
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
/**
 * count_directories - count directories
 * @path: path of directories
 * Return: nbr of directories
 */
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





