#include "shell.h"
/**
 * execute - This functios work
 * @tokenized: This is the arguments in a array of the strings
 * @command: This is my command
 * @buffer: This are the arguments in a single line or a strings
 * @mypath: This is the path of the enviroment
 * Return: Void
 **/
void execute(char **tokenized, char *command, char *mypath, char *buffer)
{
	 int child_pid = 0, status, exitstatus = 0;

  if (tokenized[0] != NULL && strcmp(tokenized[0], "exit") == 0)
  {
    printf("\n");
    free_grid(tokenized);
    free(buffer);
    exit(0);
  }

  /* Retrieve PATH environment variable only once */
  mypath = _getenv("PATH");

  /* Find the executable file */
  command = execute1(tokenized, mypath);
 
	if (command != NULL)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			free(command);
			free_grid(tokenized);
			return;
			}
		if (child_pid == 0)
			execve(command, tokenized, environ);

	free(command);
	wait(&status);

	if (WIFEXITED(status))
		exitstatus = WEXITSTATUS(status);

	else if (WIFSIGNALED(status))
	{
		printf("\n");
		printerror(2, tokenized);
	}
	free(command);
	}
	(void)exitstatus;
	free_grid(tokenized);
}