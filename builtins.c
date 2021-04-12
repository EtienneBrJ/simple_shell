#include "shell.h"

char *_getline(char *buffer)
{
    int rd;
    char c;
    int i = 0;
      
    c = '\0';

    while (c != '\n' && c != EOF)
    { 
        rd = read(STDIN_FILENO, &c, 1);
        if (rd == 0)
        {
            if (isatty(STDIN_FILENO))
                write(STDIN_FILENO, "\n", 1);
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        buffer[i] = c;        
        i++;
    }
   /* printf("%d <-- count\n", i);*/
    return(buffer);
}


int change_dir(char **argv)
{
    int a, b;
    char *home;
    
    home = _getenv("HOME");
    home = strtok(home, "=");
    home = strtok(NULL, "=");
    if (argv[1] == NULL)
    {
        a = chdir(home);
        if (a < 0)
            return (-1);
        return (0);
    }
    if (_strcmp(argv[1], "~") == 0)
    {
        b = chdir(home);
        if (b < 0)
            return (-1);
        return (0);
    }
    /* else if (_strcmp(argv[1], "-") == 0)
    {
        b = chdir(home);
        if (b < 0)

            return (-1);
        return (0);
    } */
    else
    {
        b = chdir(argv[1]);
        if (b < 0)
        perror("Path not good");
            return (-1);
        return (0);
    }
    return (0);
}

void close_shell(char **argv, char *buffer)
{
    int n = 0;
    if (argv[1] && argv[2])
    {
        _puts("too many arguments");
        free_all(buffer, argv);
        exit (EXIT_FAILURE);
    }
	if (_isnumber(argv[1])) /*on doit créer une fonction qui check si c'est un numberen prenant en compte + et - (on va devoir utiliser _isdigit qu'on a deja fait) */	                        
    {
        n = _atoi(argv[1]);
        free_all(buffer, argv);
        exit (n);
    }
	free_all(buffer, argv);
	exit (EXIT_SUCCESS);
}

/**  _atoi d'Octave du printf, peut etre des modifs a faire
 * _atoi - convert a string to an integer
 * @s: a pointer
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	int ite1 = 0, ite2, num = 0, sign = 1;

	while (s[ite1] != '\0' && (s[ite1] < '0' || s[ite1] > '9'))
	{
		if (s[ite1] == '-')
		{
			sign *= -1;
		}
		ite1++;
	}
	ite2 = ite1;
	while (s[ite2] >= '0' && s[ite2] <= '9')
	{
		num = (num * 10) + (s[ite2] - '0') * sign;
		ite2++;
	}
	return (num);
}

/**
 * _isnumber - check for numbers in string
 * @s: string to check 
 * Return: 1 or 0
 */
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
        if (s[i] == ' ' || s[i] == '-' || s[i] == '+')
            i++;
		while (s[i])
        {
            if (!_isdigit(s[i]))
			    return (EXIT_FAILURE);
        }
	}
	return (EXIT_SUCCESS);
}

/**
 * _isdigit - check if digit
 * @c: digit to check
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}