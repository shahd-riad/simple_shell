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

#define READ_BUF 1024
#define WRITE_BUF 1024

int _putchar(char c);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_memset(char *s, char b, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
