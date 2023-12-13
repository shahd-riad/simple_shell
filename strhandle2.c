#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or
 * NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	int length = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	while (*str++)
		length++;

	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);

	for (length++; length--;)
		dup[length] = *--str;

	return (dup);
}
/**
 * starts_with - Checks if a string starts with another string.
 * @haystack: The string to check.
 * @needle: The prefix to check for.
 *
 * Return: Pointer to the character in haystack after the prefix,
 *         or NULL if the prefix is not found.
 */
char *starts_with(char *haystack, char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _erratoi - Converts a string to an integer with error checking.
 * @s: The string to convert.
 *
 * Return: The converted integer if successful, or -1 on error.
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (result);
}

/**
 * countElements - Count the number of elements in an array of strings
 * @array: The array of strings
 *
 * Return: The number of elements in the array
 */
int countElements(char **array)
{
	int count = 0;

	while (array[count] != NULL)
	{
		count++;
	}

	return (count);
}

