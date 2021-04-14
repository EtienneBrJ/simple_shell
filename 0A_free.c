#include "shell.h"
/**
 * free_exit - function that free all
 * @buffer: buffer
 * @argv: command line
 *
 */
void free_exit(char *buffer, char **argv)
{
	free(buffer);
	free_double_ptr(argv);

}
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
 * free_all - function that free all
 * @buffer: buffer
 * @argv: command line
 */
void free_all(char *buffer, char **argv)
{
	free(buffer);
	free_double_ptr(argv);
}
