#include "shell.h"

/**
 * _exit - closes the shell
 * @args: argument
 * Return: 0
 */
int _exit(char **args)
{
	return (0);
}

/**
 * _cd - navating/changing to directories
 * @args: list of 2 arguments
 * Return: args[1] which is directory
 */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
		perror("lsh");
		}
	}
	return (1);
}
