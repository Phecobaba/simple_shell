#include "shell.h"

/**
 * str_cpy - copy content from one file to another
 * @dest: copy into
 * @src: copy from
 * Return: dest
 */

char *str_cpy(char *dest, char *src)
{
	int a = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';

	return (dest);
}

/**
 * str_cat - copy content from one file and append to another
 * @dest: append into
 * @src: copy from
 * Return: dest
 */

char *str_cat(char *dest, char *src)
{
	int a = 0, b = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (; dest[a] != '\0'; a++)
		;
	for (; src[b] != '\0'; b++)
	{
		dest[a++] = src[b];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * strn_cmp - compare contents/string
 * @s1: string to compare with
 * @s2: string to compare
 * @n: size of string
 * Return: 1, -1 or 0
 */

int strn_cmp(const char *s1, const char *s2, size_t n)
{
	size_t a = 0;

	for (; a < n; a++)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		if (s1[a] == '\0' && s2[a] == '\0')
			return (0);
	}
	return (0);
}
/**
 * str_chr - search for a character in string
 * @s: string to search
 * @c: character to find
 * Return: string from first occurrence of c
 */

char *str_chr(const char *s, int c)
{
	int a = 0;

	if (s == NULL)
		return (NULL);
	while (s[a] != '\0')
	{
		if (s[a] == c)
			return ((char *)s + a);
		a++;
	}
	return (NULL);
}

/**
 * str_dup - duplicate string
 * @s: string to duplicate
 * Return: duplicated string
 */

char *str_dup(const char *s)
{
	char *dup;
	int a = 0;

	dup = (char *)malloc(sizeof(char) * str_len(s) + 1);
	if (!dup)
	{
		free(dup);
		return (NULL);
	}

	while (*s != '\0')
		dup[a++] = *s++;
	dup[a] = '\0';

	return (dup);
}
