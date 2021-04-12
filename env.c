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

void set_env(char *buffer, char **argv, list_t *head)
{
    size_t lenght_list;

    if (argv[1] ==  NULL)
    {
        free(buffer);
        free_double_ptr(argv);
    }
    else if (argv[1] && argv[2])
        {
            puts("too many arguments");
            free(buffer);
            free_double_ptr(argv);           
        }
    else
    {
        lenght_list = listint_len(head);
        lenght_list++;
        add_node_end(&head, argv[1], lenght_list);
    }
    
}

void unset_env(char *buffer, char **argv, list_t *head)
{
    list_t *tmp = head;
    size_t idx = 0;
    if (argv[1] ==  NULL)
    {
        free(buffer);
        free_double_ptr(argv);
    }
    else if (argv[1] && argv[2])
        {
            puts("too many arguments");
            free(buffer);
            free_double_ptr(argv);           
        }
    else
    {
	    while (tmp)
	    {
            if (_strcmp(tmp->str, argv[1]) == 0)
            {
               delete_nodeint_at_index(&head, idx);
            }
            tmp = tmp->next;
            idx++;
	    }
    }
}



