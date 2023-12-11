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