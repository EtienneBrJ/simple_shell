#include "shell.h"

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
env_l *add_node_end(env_l **head, char *name, char *value)
{
    env_l *new_node;
	env_l *tmp;

	new_node = malloc(sizeof(env_l));
	if (new_node == NULL)
		return (NULL);
	new_node->name = _strdup(name);
	new_node->value = _strdup(value);
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


env_l *_parsingenv(char *env_name)
{
	char *name, *token, *var_env;
    extern char **environ;
    env_l *env_list = NULL;
    int i;

	var_env = _getenv(env_name);

	token = strtok(var_env, "=");

	if (token == NULL)
		return;

	name = token;

	while (token != NULL && (_strcmp(token, "\n") != 0))
	{
        if (token != env_name)
		    add_node_end(&env_list, name, token);
		token = strtok(NULL, ":");
	}


	return (env_list);
}