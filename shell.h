#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;
#define STORE 1024

size_t str_len(const void *c);
char *str_dup(const char *s);
char *str_chr(const char *s, int c);
char *str_tok(char *s, const char *delim);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
int strn_cmp(const char *s1, const char *s2, size_t n);
void signal_handler(int signal);
void env_h(void);
void freee_s(char **f);
int check_ifs(char **tok, char *w);
ssize_t get_line(char **line_p, size_t *n, FILE *stream);
void exit_st(char **s);
char *_getenv(const char *name);
char pathfinder(char *tok, char **token, char **argv);
int exec_c(char *path, char **token, char **argv);
int pipe_input(char **argv);

#endif
