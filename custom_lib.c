#include "shell.h"

/**
 * str_tok - parses strings into tokens
 * @s: string to parse
 * @delim: delimiter
 * Return: parsed strings
 */

char *str_tok(char *s, const char *delim)
{
	static char *keep;
	char *tok;
	const char *del;

	if (s != NULL)
		keep = s;
	if (keep == NULL)
		return (NULL);

	tok = keep;
	while (*keep)
	{
		del = delim;
		while (*del)
		{
			if (*keep == *del)
			{
				*keep = '\0';
				keep++;

				if (tok != keep)
				{
					return (tok);
				}
				else
				{
					tok++;
					break;
				}
			}
			del++;
		}
		keep++;
	}
	keep = NULL;
	return (tok);
}

/**
 * exit_st - exit status
 * @token: command
 * Return: nothing
 */

void exit_st(char **token)
{
	int status;

	if (token[1] != NULL)
		status = atoi(token[1]);
	else
		status = 0;
	exit(status);
}

/**
 * str_len - retrieve length of a string of any type
 * @c: string
 * Return: total number of bytes
 */

size_t str_len(const void *c)
{
	const char *str = (char *)c;
	size_t a = 0;

	while (str[a] != '\0')
		a++;

	return (a);
}

/**
 * get_line - grab uses input from terminal
 * @line_p: string to grab
 * @n: total amount of byte to read at a time
 * @stream: where to read from
 * Return: number of bytes read
 */

ssize_t get_line(char **line_p, size_t *n, FILE *stream)
{ size_t i = 0, contain = *n;
	ssize_t byt_read = 0;
	int s;

	if (line_p == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*n == 0)
		*n = STORE;
	if (*line_p == NULL)
	{
		*line_p = (char *)malloc(*n);
		if (*line_p == NULL)
			return (-1);
	}
	while ((s = fgetc(stream)) != EOF && s != '\n')
	{
		if (i >= contain - 1)
		{ char *tmp;

			contain *= 2;
			tmp = (char *)realloc(*line_p, contain);
			if (tmp == NULL)
			{
				free(*line_p);
				*line_p = NULL;
				return (-1);
			}
			*line_p = tmp;
		}
		(*line_p)[i++] = (char)s;
		byt_read++;
	}
	if (byt_read == 0 && s == EOF)
	{ free(*line_p);
		*line_p = NULL;
		return (-1);
	}
	(*line_p)[i] = '\0';
	*n = contain;
	return (byt_read);
}

/**
 * _getenv - locate a builtin key=value
 * @name: key=value to find
 * Return: value
 */
char *_getenv(const char *name)
{
	char **ev = environ;

	if (name == NULL)
		return (NULL);

	while (*ev != NULL)
	{
		char *p = *ev;
		char *c = str_chr(p, '=');

		if (c != NULL && c > p && strn_cmp(name, p, str_len(name)) == 0)
			return (c + 1);
		ev++;
	}
	return (NULL);
}
