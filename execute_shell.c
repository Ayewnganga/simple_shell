#include "shell.h"

/**
 * lsh_launch - executes shell
 * @args: array of strings
 * Return: status code
 */
int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("lsh");
	} else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * lsh_execute - runs the launch  function
 * @args: array of strings
 * Return: lsh_launch
 */
int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	return (lsh_launch(args));
}
