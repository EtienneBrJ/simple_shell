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
    printf("%d <-- count\n", i);
    return(buffer);
}


