#include "shell.h"

/**
 * getnbw - get number of words
 * @str: string to split
 * @ascii: array of delimeters that separate words
 * Return: nb of words in string
 */
int getnbw(unsigned char *str, int ascii[])
{
	int i, nbword;

	i = 0;
	nbword = 0;
	while (*(str + i) != '\0')
	{
		if (i == 0 && ascii[*str] != 1)
			nbword++;
		if (ascii[*(str + i)] == 1 && ascii[*(str + i + 1)] != 1 &&
		    *(str + i + 1) != '\0')
			++nbword;
	i++;
	}
	return (nbword);
}


/**
 * _strw - length of word
 * @s: string
 * @ascii: indicates end of words
 * Return: length of word at initial start of s
 */
int _strw(unsigned char *s, int ascii[])
{
	int i;

	i = 0;
	while (ascii[*(s + i)] != 0 && *(s + i) != '\0')
		++i;
	return (i);
}

/**
 * _getw - extract word from string
 * @s: string
 * @dest: destination string for word
 * @l: size of string
 * Return: word at beginning of string
 */
char *_getw(unsigned char *s, char *dest, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		printf("%c--", *(s + i));
		*(dest + i) = *(s + i);
		++i;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * strtow - string to words strtok with given delimiter
 * @string: string to split
 * @d: a string, the delimeters
 * As it is, words can be separated by the delimeters
 * It is NULL terminated
 * Return: pointer to pointer to char
 */
char **strtow(char *string, char *d)
{
	int i, nbword, ascii[128];
	char **s, **remainder, *tmp;
	unsigned char *t, *str;

	t = (unsigned char *)d;
	str = (unsigned char *)string;
	for (i = 0; i < 128; ++i)
		ascii[i] = 0;
	for (; *t; t++)
		ascii[*t] = 1;

	nbword = getnbw(str, ascii);
	if (nbword == 0)
		return (NULL);
	s = malloc((nbword + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	remainder = &string;
	for (i = 0; i < nbword; ++i)
	{
		s[i] = _strtok_r(&tmp, NULL, d, remainder);
	}
	s[i] = NULL;
	return (s);
}

/**
 * free_strtow - free a **char NULL terminated
 * @s: a **char
 */
void free_strtow(char **s)
{
	int i;

	if (!s || *s == NULL)
		return;
	for (i = 0; s[i] != NULL; ++i)
		;
	while (--i >= 0)
		free(s[i]);
	free(s);
}
