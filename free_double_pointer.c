#include "shell.h"

void free_double_ptr(char **double_point)
{
	unsigned int i = 0;

	if (double_point == NULL)
		return;

	while (double_point[i])
	{
		free(double_point[i]);
		++i;
	}

	if (double_point[i] == NULL)
		free(double_point[i]);

	free(double_point);
}
