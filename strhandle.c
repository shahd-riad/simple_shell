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
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;											}
	return (len);
}

/**
 *  * _strcpy - update value.
 *   * @dest: value to be evaluated.
 *    * @src: value to be evaluated.
 *     * Return: 0
*/
char *_strcpy(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
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
	int sum1;
	int sum2;
	int len;

	sum1 = 0;
	sum2 = 0;
	for (len = 0; s1[len] != '\0'; len++)
	{
		sum1 += (int)s1[len];
	}
	for (len = 0; s2[len] != '\0'; len++)
	{
		sum2 += (int)s2[len];
	}
	return (sum1 - sum2);
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
	int length, i;

	length = 0;
	i = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	for (i = 0; src[i] != '\0'; ++i, length++)
	{
		dest[length] = src[i];
	}
	dest[length] = '\0';
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
