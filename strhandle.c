#include "shell.h"

/**
 *  * _putchar - function that prints a character c to stdout
 *   * @c: character to be printed
 *    *
 *     * Return: The write function which is responsible for printing @c
 *      */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 *  * _puts - prints a string, to stdout
 *   * @str: value to evaluate.
 *    * Return: void
*/

void _puts(char *str)
{
		int l;

		l = 0;
		while (*(str + l) != '\0')
		{
			_putchar(str[l]);
			l++;
		}
		_putchar('\n');
}

/**
 *  * _strlen - returns the length of a string.
 *   * by traversing throughout the values of string s
 *    * as it increments variable length and stops the loop at the end of
 *	the string
 *     * with len incremented to fit the length of the string
 *      * @s: value to evaluate.
 *       * Return: len
*/

int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
	{
	}
	return (l);
}

/**
 *  * _strcpy - update value.
 *   * @dest: value to be evaluated.
 *    * @src: value to be evaluated.
 *     * Return: 0
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
/**
 *  * _strcmp - compares 2 strings
 *   * @s1: first string
 *    * @s2: second string
 *     *
 *      * Description: works exactly like strcmp from <string.h>
 *       *
 *        * Return: -ve integer, 0 or +ve integer if s1 is less than,
 *         * equal to or greater than s2
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);
}
/**
 *_strcat - Write a function that concatenates two strings.
 *
 *@dest: This is the output dest
 *@src: This is the input source
 *
 * Return: This return to dest, that concatenates two strings
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
	{
	}
	dest[a] = '/';
	a++;
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
/**
 * _strstr - function to find a string within another string
 * @haystack: string where we will search
 * @needle: string to find
 * Return: string found
 **/
char *_strstr(char *haystack, const char *needle)
{
	char *c;

	while (*haystack)
	{
		while (*needle == *haystack)
		{
			haystack++, needle++;
		}
		if (*needle == '\0')
		{
			if (*haystack == '=')
			{
				haystack++;
				c = haystack;
				return (c);
			}
			return (NULL);
		}
		haystack++;
	}
	return (NULL);
}
