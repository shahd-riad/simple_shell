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
int count_words(char *text)
{
    int word_count = 0;
    int in_word = 0;
	char *c;

    for (c = text; *c != '\0'; ++c) {
        if ((*c) != ' ' && !in_word) {
            in_word = 1;
            word_count++;
        } else if ((*c) == ' ' && in_word) {
            in_word = 0;
        }
    }
    return word_count;
}