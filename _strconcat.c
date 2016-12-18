#include "shell.h"

/**
 * _strconcat - concatenate 2 strings
 * @s1: first string, malloc'ed or realloc'ed
 * @s2: Buffer of length BUF_LENGTH to add to first string
 * Return: pointer to modified first string
 */
char *_strconcat(char *s1, char *s2)
{
        unsigned int l1, i;

	if (s2 == NULL)
		return (s1);

	i = 0;
	l1 = 0;
        if (s1 == NULL)
        {
		printf("%s %i malloc\n", __FILE__, __LINE__);
                s1 = malloc(sizeof(*s1) * (BUF_LENGTH + 1));
                if (s1 == NULL)
                        return (NULL);
        }
        else
	{
		printf("%s s1 %s\n", __FILE__, s1);
                l1 = _strlen(s1);
                s1 = _realloc(s1, l1, l1 + BUF_LENGTH + 1);
	}
	i = l1;
	while (i < (l1 + BUF_LENGTH))
                *(s1 + i++) = *s2++;

        *(s1 + i) = '\0';
        return (s1);
}
