#include "shell.h"
/**
 * _calloc - malloc and fill allocated mem with 0
 * @nmemb: unsigned int
 * @size: unsigned int
 * Return: pointer to aloocated mem
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		s[i] = 0;
	return (s);
}
/**
 * free_double_ptr - free double pointers
 * @double_point: double ptr
 */
void free_double_ptr(char **double_point)
{
	int i = 0;

	if (double_point == NULL)
		return;

	while (double_point[i])
	{
		free(double_point[i]);
		i++;
	}
	/*if (double_point[i] == NULL)*/
		free(double_point[i]);

	free(double_point);
}
/**
 * _realloc - reallocates a memory using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes if the allocated space for ptr
 * @new_size: new size in bytes of the memory block
 *
 * Return: pointer to the new block
 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p_new;
	unsigned int i;
	char *ptr1;

	ptr1 = ptr;

	if (!ptr1)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	p_new = malloc(new_size);
	if (!p_new)
		return (NULL);

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			p_new[i] = ptr1[i];
	}
	free(ptr);
	return (p_new);
}



