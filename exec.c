#include "shell.h"

/**
 * pathfinder - find path/location of file for command without PATH
 * @tok: command entered by user
 * @token: argument entered by user
 * @argv: used to get the name of our file for error purpose
 * Return: PATH/location joined with command or ERROR if path is not found
 */

char pathfinder(char *tok, char **token, char *argv[])
{
	char *pt = _getenv("PATH"), *p = str_dup(pt), *d, *f_pth;

	if (p == NULL)
		return (-1);
	
	d = str_tok(p, ":");
	if (d == NULL)
	{
		perror(argv[0]);
		free(p);
		return (-1);
	}
	
	f_pth = malloc(str_len(d) + str_len(tok) + 2);
	if (!f_pth)
	{
		perror(argv[0]);
		free(p);
		return (-1);
	}
	
	while (d != NULL)
	{
		str_cpy(f_pth, d);
		str_cat(f_pth, "/");
		str_cat(f_pth, tok);
		if (access(f_pth, X_OK) == 0)
		{
			int got;

			got = exec_c(f_pth, token, argv);
			free(p);
			free(f_pth);
			return (got);
		}
		d = str_tok(NULL, ":");
	}

	perror(argv[0]);
	free(p);
	free(f_pth);
	return (-1);
}

/**
 * exec_c - executes command
 * @path: command parsed through main()
 * @token: argument parsed through main()
 * @argv: used to get file name
 * Return: non zero, cause it never returns after execution
 */

int exec_c(char *path, char **token, char *argv[])
{
	pid_t pid;
	int status;

	if (access(path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(path, token, environ) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	else
	{
		pathfinder(path, token, argv);
	}
	return (-1);
}
