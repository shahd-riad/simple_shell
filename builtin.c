#include "shell.h"

/**
 * is_builtin - Checks if a command is a built-in.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in, 0 otherwise.
 */
int is_builtin(char *command)
{
	int i;

	for (i = 0; i < sizeof(builtins) / sizeof(builtins[0]); ++i)
	{
		if (strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * handle_builtin - Handles execution of built-in commands.
 * @tokens: The array of tokens representing the command.
 *
 * Return: None.
 */
void handle_builtin(char **tokens)
{
	if (strcmp(tokens[0], "setenv") == 0)
	{
		if ( != 3)
			write(STDERR_FILENO, "wrong number of arguments\n", 54);
		_setenv(tokens[1], tokens[2], 1);
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
	{
		if (sizeof(tokens) / sizeof(tokens[0]) != 2)
			write(STDERR_FILENO, "too many arguments\n", 54);
		_unsetenv(tokens[1]);
	}
	else if (strcmp(tokens[0], "exit") == 0)
	{
		if (sizeof(tokens) / sizeof(tokens[0]) != 2)
			write(STDERR_FILENO, "too many arguments\n", 54);
		my_exit(tokens[1]);
	}
}
/**
 * _setenv - Sets or updates an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: Flag indicating whether to overwrite an existing variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(char *name, char *value, int overwrite)
{
	char *env;
	int i = 0;

	if (!name || !value)
		return (0);

	while (*environ[i] != '\0')
	{
		env = _strstr(environ[i], name);

		if (env == NULL)
			i++;
		else if (_strcmp(env, name) == 0)
		{
			if (overwrite)
			{
				free(environ[i]);
				environ[i] = malloc(_strlen(name) + _strlen(value) + 2);

				_strcpy(environ[i], name);
				_strcat(environ[i], "=");
				_strcat(environ[i], value);
				if (environ[i] == NULL)
					return (-1);
				return (0);
			}
			else
			{
				write(STDERR_FILENO, "Variable already exists.\n", 54);
				return (-1);
			}
		}
		else
			_newenv(name, value);
	}
	return (-1);
}
/**
 * _newenv - Creates a new environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int _newenv(char *name, char *value)
{
	char *buff;
	int i, j, envcount = 0;
	char **new_environ;

	if (!name || !value)
		return (0);

	while (*environ[i] != '\0')
		envcount++;

	new_environ = malloc(sizeof(char *) * (envcount + 2));
	buff = malloc(_strlen(name) + _strlen(value) + 2);

	if (buff == NULL || new_environ == NULL)
		return (-1);

	for (j = 0; j < envcount; j++)
	{
		new_environ[i] = _strdup(environ[i]);

		if (new_environ[i] == NULL)
			free_grid(new_environ);
	}

	_strcpy(buff, name);
	_strcat(buff, "=");
	_strcat(buff, value);
	new_environ[envcount] = _strdup(buff);

	if (new_environ[envcount] == NULL)
	{
		free(buff);
		free_grid(new_environ);
	}

	new_environ[envcount + 1] = NULL;
	environ = new_environ;

	return (0);
}
/**
 * _unsetenv - Removes an environment variable.
 * @name: The name of the environment variable to remove.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(char *name)
{
	char *env, *check;
	int i = 0, j = 0, cnt = 0;
	char **newenvr;

	if (!name)
		return (-1);

	while (*environ[cnt] != '\0')
		cnt++;

	newenvr = malloc(sizeof(char *) * (cnt));

	if (newenvr == NULL)
		return (-1);

	for (i = 0; i < cnt; i++)
	{
		env = environ[i];
		check = starts_with(env, name);

		if (check != NULL && *check == '=')
			continue;
	}

	newenvr[j++] = _strdup(environ[i]);

	if (newenvr == NULL)
	{
		free_grid(newenvr);
		return (-1);
	}

	newenvr[j] = NULL;
	free_grid(environ);
	environ = newenvr;

	return (0);
}



