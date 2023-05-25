#include "shell.h"
/**
 * signal_handler - reprompts the shell(cursor)
 * @signal: signal input
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
/**
 * freee_s - free string
 * @f: input
 * Return: void
 */
void freee_s(char **f)
{
	char **c;

	if (f == NULL)
		return;
	c = f;
	for (; c != NULL; c++)
	{
	free(*c);
		*c = NULL;
	}
	free(f);
}
/**
 * env_h - print environment
 *
 * Return: nothing
 */
void env_h()
{
	char **env = environ;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, str_len(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
