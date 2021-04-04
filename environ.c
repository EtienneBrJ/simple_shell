#include "shell.h"

typedef struct environment
{
	char *name;
	char *value;
	environment *next;
} environment;

/**
 * *_strdup - return a pointer to a copy of the string
 *@str: string
 *Return: poiter to dest or NULL
 */
char *_strdup(char *str)
{
	char *dest;
	unsigned int i;

	if (str == NULL)
	{
		return (NULL);
	}

	dest = malloc((_strlen(str) + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}
	return (dest);
}

/**
 *add_node_end - add a new nod at the end of list_t
 *@head: head of list_t
 *@str: pointer to string to insert
 *Return: the adress of the new ellement or null if it failed
 */
environment *add_node_end(environment **head, char *str, char *token)
{
	environment *new_node;
	environment *tmp;

	new_node = malloc(sizeof(environment));
	if (new_node == NULL)
		return (NULL);
	new_node->name = _strdup(str);
	new_node->value = _strlen(str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
/**
 *_strcmp - compare two string
 *@s1: string
 *@s2: string
 *Return: 0 if same return else
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; s1[i] != '\0' && s2[i] != '\0' ; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}


environment _parsingenv(char *env_name)
{
	int i;
	char *name, *token, *var_env;
	environment env_list;

	var_env = _getenv(env_name);
	token = strtok(*environ[i], "=" );

	if (token == NULL)
		return;

	name = token;

	while (token != NULL && _strcmp(token, "\n") != 0)
	{
		add_node_end(&env_list, name, token);
		token = strtok(NULL, ":");
	}
	return(env_list);
}
