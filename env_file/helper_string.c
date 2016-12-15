#include "shell.h"

/*
 * this file contains helper functions for strings
 * _strlen
 * check_first
 * _strdup
 * _memcpy
 * _strchr
 */


/**
 * _strlen - retur length of string
 * @s: a string
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	if (!s)
		return (0);
	for (i = 0; *s++ != '\0'; ++i)
		;
	return (i);
}


/**
 * check_first - check if string in is at the begining of string s
 * @s: string to check
 * @in: string to look for
 * Return: 1 if true, 0 if false
 */
int check_first(char *s, const char *in)
{
	int i;

	i = 0;
	while (*(s + i) == *(in + i) && *(s + i) != '\0' && *(in + i) != '\0')
		++i;

	if (*(in + i) == '\0')
		return (1);

	return (0);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to copy to new space in memory
 * returns a pointer to a newly allocated space in memory, which contains
 * a copy of the string given as a parameter.
 * Return: a pointer to the duplicated string. NULL if insufficient memory
 */
char *_strdup(const char *str)
{
	int l, i;
	char *s;

	if (str == NULL)
		return (NULL);
	l = _strlen(str);
	s = malloc((l + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	i = 0;
	while (i <= l)
	{
		*(s + i) = *(str + i);
		i++;
	}
	return (s);
}

/**
 * _memcpy - simple version of memcopy()
 * @dest: memory area to print to
 * @src: memoy area to print from
 * @n: number of bytes to copy from src to dest
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}



/**
 * _strchr - simple version of strchr()
 * @s: string in which we want to locate given byte
 * @c: char or byte to locate, \0 works
 *
 * Return: pointer to first occurence of c or NULL otherwise
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (NULL);
}
