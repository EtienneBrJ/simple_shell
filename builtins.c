#include "shell.h"

char *_getline(list_t *head)
{
    char c = '\0', *buffer;
    int i = 0, rd, bufferSize = BUF_SIZE;

    buffer = malloc(sizeof(char) * BUF_SIZE + 1);

    while (c != '\n' && c != EOF)
    {
        rd = read(STDIN_FILENO, &c, 1);

        if (rd == 0)
        {
            c = EOF;
            write(STDIN_FILENO, "\n", 1);
            free(buffer);
            free_list(head);
            exit(EXIT_SUCCESS);
        }

        if (i >= bufferSize - 1)
        {
            buffer = _realloc(buffer, bufferSize, sizeof(char) * (i + 2));
            bufferSize = i + 2;
        }
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';


    return (buffer);
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

void close_shell(char **argv, char *buffer, list_t *head)
{
    int n = 0;
    if (argv[1] == NULL)
    {
        free_all(buffer, argv, head);
        exit (EXIT_SUCCESS);
    }
    if (argv[1] && argv[2])
    {
        _puts("too many arguments");
        free_all(buffer, argv, head);
        exit (EXIT_FAILURE);
    }
    if (_isnumber(argv[1]))                
    {
        n = _atoi(argv[1]);
        free_all(buffer, argv, head);
        exit (n);
    }
}