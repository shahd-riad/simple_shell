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
 * word_len - function to count number of letters of
 * each word
 * @str: word
 * Return: number of letters of tje word
**/
int word_len(char *word)
{
  int length = 0;
  while (*word != '\0' && (*word) != ' ') {
    length++;
    word++;
  }
  return length;
}
/**
 * count_words - functin to count number of words
 * @text: string
 * Return: number of words
**/
int count_words(char *str)
{
    int index = 0, words = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;
	for (index = 0; index < len; index++)
	{
		if (*(str + index) != ' ')
		{
			words++;
			index += word_len(str + index);
		}
	}
	return (words);
}