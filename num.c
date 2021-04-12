 #include "shell.h"
 
/**  _atoi d'Octave du printf, peut etre des modifs a faire
 * _atoi - convert a string to an integer
 * @s: a pointer
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	int ite1 = 0, ite2, num = 0, sign = 1;

	while (s[ite1] != '\0' && (s[ite1] < '0' || s[ite1] > '9'))
	{
		if (s[ite1] == '-')
		{
			sign *= -1;
		}
		ite1++;
	}
	ite2 = ite1;
    while (s[ite2] >= '0' && s[ite2] <= '9')
	{
		num = (num * 10) + (s[ite2] - '0') * sign;
		ite2++;
	}
	return (num);
}

/**
 * _isnumber - check for numbers in string
 * @s: string to check 
 * Return: 1 or 0
 */
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
        if (s[i] == ' ' || s[i] == '-' || s[i] == '+')
            i++;
		while (s[i])
        {
            if (!_isdigit(s[i]))
			    return (EXIT_FAILURE);
        }
	}
	return (EXIT_SUCCESS);
}

/**
 * _isdigit - check if digit
 * @c: digit to check
 * Return: 1 or 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}