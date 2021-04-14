#include "shell.h"

/**
 * add_node_end - adds a new node at the end of the list
 * @head: pointer to pointer to the list
 * @str: string to put in the new node
 * @index: index
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, char *str, unsigned int index)
{
	list_t *newnode;
	list_t *tmp = *head;

	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);

	newnode->index = index;
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
/**
 * init_list_env - initialise environment linkedlist
 * @h: struct
 * Return: struct (h)
 */
list_t *init_list_env(list_t *h)
{
	static int index;

	for (index = 0; environ[index]; index++)
	{
		add_node_end(&h, environ[index], index);
	}
	return (h);
}
/**
 * print_list - print struct of environ
 * @h: struct
 * Return: index
 */
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

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: pointer to the list
 * Return: numbers of elements in the list
 */
size_t listint_len(list_t *h)
{
	size_t nb = 0;

	while (h)
	{
		nb++;
		h = h->next;
	}
	return (nb);
}

/**
 * delete_node_at_index - deletes the node at index index of a listint_t
 * linked list
 * @head: pointer to pointer
 * @index: index of the list
 * Return: 1 if it's succeeded and -1 if it's failed
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *tmp = *head;
	list_t *replace;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	while (i < index - 1)
	{
		if (!tmp)
			return (-1);
		tmp = tmp->next;
		i++;
	}

	replace = tmp->next;
	tmp->next = replace->next;

	free(replace->str);
	free(replace);



	return (1);
}
