#include "shell.h"
/**
  * _getenv - function to print the environment variable
  * @name: command coming
  * Return: environment variable
**/
char *_getenv(char *name)
{
	char *env;
	int i = 0;
	
	while (*environ[i] != '\0')
	{
		env = _strstr(environ[i], name);
		
		if (env == NULL)
			i++;

		else
			return (env);
		
	}
	return (NULL);
}

/**
  * tokenize - functin to tokenize the command given
  * @buffer: command given
  * Return: array of strings tokenized
**/
char **tokenize(char *buffer)
{
	int tokens, i = 0;
	char *token, **token_list;

	tokens = count_words(buffer);

	if (tokens == 0)
		return (NULL);
		
	token = strtok(buffer, DELIM);
	token_list = malloc(sizeof(char*) * (tokens + 1));

	while (token != NULL)
	{
		token_list[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		token_list[i] = _strcpy(token_list[i], token);
		token = strtok(NULL, DELIM);
		i++;
	}
	token_list[i] = NULL;
	return (token_list);
}

/**
 * free_grid - function to free an array memory
 * @grid: array of strings
 * Return: void
**/
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

/**
 * execute1 - function to execute child process
 * @tokeni: tokenized array
 * @path: path
 * Return: void
**/
char  *execute1(char **tokens, char *path)
{
	char *token = NULL, *combined = NULL, *temp = NULL;
	const char s[2] = ":";
	struct stat st;

	/* checks if the process is exectuable on its own aka has the full path */
	if (stat(tokens[0], &st) == 0)
	{
		combined = malloc(sizeof(char) * (_strlen(tokens[0]) + 1));
		combined = _strcpy(combined, tokens[0]);
		return (combined);
	}
	else
	{
		temp = malloc(sizeof(char) * (_strlen(path) + 1));
		temp = _strcpy(temp, path);
		token = strtok(temp, s);

		while (token != NULL)
		{
			combined = malloc(sizeof(char) * (_strlen(token) + _strlen(tokens[0]) + 1));
			combined = _strcpy(combined, token);
			combined = _strcat(combined, tokens[0]);
			if (stat(combined, &st) == 0)
			{
				return (combined);
			}
			token = strtok(NULL, s);
			free(combined);
		}
		free(temp);
	}
	return (NULL);
}