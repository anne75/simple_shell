#include "shell.h"

/*this file includes
 * _strcmp
 * _strchr_r
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
 * _strchr_r - strchr reverse: find the last occurence of a char in a string
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
