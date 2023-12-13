#include "shell.h"

/**
 * printerror - Print error messages to stderr.
 * @errnum: The error number.
 * @program_name: The name of the program.
 */
void printerror(int errnum, char **tokenized)
{
	char *program_name = tokenized[0];

	if (errnum == 1)
	{
		/* Print "command not found" error */
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": not found\n", 12);
	}
	else if (errnum == 2)
	{
		/* Print "executable file not found" error */
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, program_name, _strlen(program_name));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
