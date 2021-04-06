#include "shell.h"

void print_environment(char **environ)
{
    int i, length;

    i = 0;

    while (environ[i])
    {
        length = _strlen(environ[i]);

        write(STDOUT_FILENO, environ[i], length);
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}