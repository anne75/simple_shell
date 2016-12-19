#include "shell.h"

/**
 * getnbw - get number of words
 * @str: string to split
 * @delimeter: delimeter that separate words
 * Return: nb of words in string
 */
int getnbw(char *str, char delimeter)
{
	int i, nbword;

	i = 0;
	nbword = 0;
	while (*(str + i) != '\0')
	{
		if (i == 0 && *str != delimeter)
			nbword++;
		if (*(str + i) == delimeter && *(str + i + 1) != delimeter &&
		    *(str + i + 1) != '\0')
			++nbword;
	i++;
	}
	return (nbword);
}


/**
 * _strw - length of word
 * @s: string
 * @delimeter: indicates end of word
 * Return: length of word at initial start of s
 */
int _strw(char *s, char delimeter)
{
	int i;

	i = 0;
	while (*(s + i) != delimeter && *(s + i) != '\0')
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
char *_getw(char *s, char *dest, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		*(dest + i) = *(s + i);
		++i;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * strtow - string to words strtok with given delimiter
 * @str: string to split
 * @delimeter: a char, the delimeter
 * As it is, words can be separated by the delimeter, this delimeter
 * can be repeated, but several delimeters cannot be used at the same
 * time eg ':' and ' ' as in word: other
 * It is NULL terminated
 * Return: pointer to pointer to char
 */
char **strtow(char *str, char delimeter)
{
	int i, j, l, nbword, word;
	char **s;

	nbword = getnbw(str, delimeter);
	if (nbword == 0)
		return (NULL);
	s = malloc((nbword + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	i = j = word = 0;
	while (i < nbword)
	{
		if (j == 0 && *str != delimeter)
			word = 1;
		if (*(str + j) == delimeter && *(str + j + 1) != delimeter &&
		    *(str + j + 1) != '\0')
		{
			++j;
			word = 1;
		}
		if (word == 1)
		{
			word = 0;
			l = _strw(str + j, delimeter);
			s[i] = malloc((l + 1) * sizeof(**s));
			if (s[i] == NULL)
			{
				while (--i >= 0)
					free(s[i]);
				free(s);
				return (NULL);
			}
			s[i] = _getw(str + j, s[i], l);
			++i;
			j += l - 1;
		}
		++j;
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
