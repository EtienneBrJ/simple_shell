#include "shell.h"

/**
 * free_list - frees a list
 * @head: pointer to the first node of the list
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}

/**
 * add_node_end - adds a new node at the end of the list
 * @head: pointer to pointer to the list
 * @str: string to put in the new node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *newnode;
	list_t	*tmp = *head;

	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);


	newnode->str = strdup(str);
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = newnode;
	return (newnode);
}

list_t *init_list_env(list_t *h)
{ 
    int i;

    for (i = 0; environ[i]; i++)
    {
        /*printf("%s, environ[i]")*/
        add_node_end(&h, environ[i]);
    }
    return (h);
}

size_t print_list(list_t *h)
{
	size_t nb = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf(" %s\n", h->str);
		h = h->next;
		nb++;
	}
	return (nb);
}