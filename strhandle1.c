#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area to fill in
 * @b: constant byte to fill s with
 * @n: number of bytes to write
 *
 * Return: a pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

		for (i = 0; i < n; i++)
		s[i] = b;

return (s);
}

/**
 * _strchr -  locates a character in a string
 * @s: string to be checked
 * @c: character to be located in s
 *
 * Return: pointer to the first occurence of c in s. Otherwise NULL
*/
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
		return (s + i);
	}

		if (c == s[i])
		return (s + i);

	return (NULL);
}
/**
 *  * _strncpy - copies a string
 *   * @dest: string to copy to
 *    * @src: string to copy from
 *     * @n: maximum number of characters to copy from src
 *      *
 *       * Description:
 *        * works exactly like strncpy from <string.h>
 *         *
 *          * Return: a pointer to the resulting string dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	char *ptr;
	int i;

	i = 0;
	ptr = dest;
	while (*src && (i < n))
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest++ = '\0';
		i++;
	}
	return (ptr);
}
