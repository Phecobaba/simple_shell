#include "shell.h"

/**
 * main - entry point
 * @argv: pointer to string of character
 * @argc: pointer to number of argc
 * Return: 0 on success
 */

/*file no two after main.h. mains is for me*/
int main(int argc __attribute__((unused)), char **argv)
{ char *w = NULL;
	ssize_t n = 0;
	char *tok[STORE], *token;
	size_t num = 0;

/*	pipe_input(argv);*/
	signal(SIGINT, signal_handler);
	while (/*isatty(STDIN_FILENO)*/1)
	{
		write(STDOUT_FILENO, "ada~$ ", 6);
		fflush(stdout);
		n = get_line(&w, &num, stdin);
		if (n == -1)
		{       free(w);
			write(STDOUT_FILENO, "\n", 1);
			return (-1);
		}
		if (n == 0)
			continue;
		if (w[0] != '\n')
		{
			int a = 0;

			token = strtok(w, " \n");
			while (token != NULL && a < STORE - 2)
			{
				tok[a++] = token;
				token = strtok(NULL, " \n");
			}
			tok[a] = NULL;
			if (tok == NULL || tok[0] == NULL)
				continue;
			if (check_ifs(tok, w) == 0)
				continue;

			else
				exec_c(tok[0], tok, argv);
		}
	}
		free(w);

	return (0);
}

/**
 * pipe_input - handle input from outside our shell
 * @argv: pointer to string of chars
 * using it to get the name of our file for error purpose
 * Return: 0 on success
 */
/*
int pipe_input(char **argv)
{
	int a = 0, b;
	char st[STORE] = {0}, *tok[STORE], *token;

	if (!isatty(STDIN_FILENO))
	{
		b = read(STDIN_FILENO, st, STORE);
		if (b == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		st[b - 1] = '\0';

		token = str_tok(st, " \t\n");
		while (token && a < STORE - 1)
		{
			tok[a++] = token;
			token = str_tok(NULL, " \t\n");
		}
		tok[a] = NULL;

		if (strn_cmp(tok[0], "exit", 4) == 0)
		{
			exit_st(tok);
			exit(EXIT_FAILURE);
		}
		else
		{ exec_c(tok[0], tok, argv);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}*/

/**
 * check_ifs - handles builtins
 * @w: input
 * @tok: input
 * Return: 0
 */
int check_ifs(char **tok, char *w)
{
	if (strn_cmp(tok[0], "exit", 4) == 0)
	{
		free(w);
		exit_st(tok);
	}
	if (strn_cmp(tok[0], "env", 4) == 0)
	{
		env_h();
		return (0);
	}
	return (1);
}

