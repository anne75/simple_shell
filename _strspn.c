#include "shell.h"


/**
 * _strspn - strip the initial part of a string from unwanted chars
 * @s: a string
 * @delim: a string of unwanted chars - dealing with ASCII only
 * Return: index of the start of the good things, or -1 on error
 */
int _strspn(char *s, char *delimeter)
{
	int i;
	int ascii[128];
	unsigned char *t;

	if (s == NULL || delimeter == NULL)
		return (-1);

	for (i = 0; i < 128; ++i)
		ascii[i] = 0;

	t = (unsigned char *) delimeter;
	while (*t)
		ascii[*t++] = 1;
	i = 0;
	t = (unsigned char *) s;
	while (*(t + i) && ascii[*(t + i)] == 1)
		++i;

	return (i);
}


/**
 * _strcspn - return the first index in a string with an unwanted char
 * @s: a string
 * @delim: a string of unwanted chars
 * Return: index of the first unwanted char, or -1 on error
 */
int _strcspn(char *s, char *delimeter)
{
	int i;
	int ascii[128];
	unsigned char *t;

	if (s == NULL || delimeter == NULL)
		return (-1);

	for (i = 0; i < 128; ++i)
		ascii[i] = 0;

	t = (unsigned char *) delimeter;
	while (*t)
		ascii[*t++] = 1;

	i = 0;
	t = (unsigned char *) s;
	while (*(t + i) && ascii[*(t + i)] == 0)
		++i;

	return (i);
}



/* int main(void) */
/* { */

/* 	char *s = "il fait beau"; */
/* 	char *delimeter = "\0"; */

/* 	printf("strcspn %i-%s-\n", _strcspn(s, delimeter), s + _strcspn(s, delimeter)); */

/* 	return (0); */
/* } */
