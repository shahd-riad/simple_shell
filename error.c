#include "shell.h"
/**
  * printerror - function to print corresponding error
  * @error: number of error
  * @command: command inputted
  * Return: void
**/
void printerror(int error, char **command)
{
	if (error == 2)
	{
		_puts(command[0]);
		_puts(": No such file or directory\n");
	}
	if (error == 1)
	{
		exit(EXIT_SUCCESS);
	}

}
/**
 * my_exit - Handles the exit built-in command.
 * @arg: The argument provided to the exit command.
 *
 * Return: Always returns -1 if an error occurs.
 */
int my_exit(char *arg)
{
	int exit_status = _erratoi(arg);

	if (exit_status == 0 && _strcmp(arg, "0") != 0)
	{
		write(STDERR_FILENO, "Invalid argument for exit\n", 26);
		return (-1);
	}
	exit(exit_status);
}

