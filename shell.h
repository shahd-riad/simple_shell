#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strstr(char *haystack, const char *needle);
int word_len(char *word);
int count_words(char *text);
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void execute(char **tokenized, char *command, char *mypath, char *buffer);
char *_getenv(char *name);
char **tokenize(char *buffer);
void free_grid(char **grid);
char  *execute1(char **tokens, char *path);
void printerror(int errnum, char **tokenized);

/**---Delimitator---**/
#define DELIM " ,!¡¿?\'\"\n\t"

/**---Global variable environ---**/
extern char **environ;

#endif
