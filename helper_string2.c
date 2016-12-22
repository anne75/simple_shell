#include "shell.h"

/*this file includes
 * _strcmp
 * _strchr_r
 * _atoi
 */

/**
 * _strcmp - compare 2 strings see strcmp()
 * @s1: string to compare
 * @s2: string used as reference
 * Return: It returns the difference in value of the first characters where
 * s1 and s2 disagree
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * strchr_r - strchr reverse: find the last occurence of a char in a string
 * @s: a string
 * @c: a char
 * Return: pointer to where the char is or NULL
 */
char *strchr_r(char *s, char c)
{
	int l;

	if (!s)
		return (NULL);

	l = _strlen(s);
	--l;
	while (l >= 0 && s[l] != c)
		--l;
	if (l < 0)
		return (NULL);
	return (s + l);
}

/**
 * _atoi - convert first set of numbers in string to integer
 * @s: input
 * Return: converted integer value
 */

int _atoi(char *s)
{
	int i, j, sum;

	j = sum = 0;
	i = 1;
	while ((s[j] < '0' || s[j] > '9') && s[j] != 0)
	{
		if (s[j] == '-')
		{
			i = i * -1;
		}
		j++;
	}
	while ((s[j] >= '0' && s[j] <= '9') && s[j] != 0)
	{
		if (sum >= 0)
		{
			sum = -(s[j] - '0');
			j++;
		}
		else
		{
			sum = sum * 10 - (s[j] - '0');
			j++;
		}
	}
	i = i * -1;
	return (sum * i);
}
