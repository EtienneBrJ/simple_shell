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





