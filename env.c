#include "shell.h"

char *_getenv(char *var_env_name)
{
	int i = 0;

	while (*environ[i])
	{
		if (_strstr(environ[i], var_env_name) != NULL && environ[i][0] == var_env_name[0])
			return (environ[i]);
		i++;
	}
	return (NULL);
}

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

void set_env(char *buffer, char **argv)
{
    
    int i = 0;
    if (argv[1] ==  NULL)
    {
        printf("test");
        free_all(buffer, argv);
    }
    else if (argv[1] && argv[2])
        {
            puts("too many arguments");
            free_all(buffer, argv);
            
        }
    else
    {
        while (environ[i] != NULL)
            i++;

        environ[i] = argv[1];
        environ[i + 1] = NULL;
        free(buffer);
        free(argv[0]);
    }
    
}

/*void unset_env(char **environ)
{
    int i = 0;
}
*/
