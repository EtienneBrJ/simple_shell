#include "shell.h"

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