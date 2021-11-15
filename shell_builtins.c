#include "shell.h"

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};
int (*builtin_funct[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

/**
 * lsh_num_builtins - list builtins commands
 * Return: builtin command
 */
int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * lsh_help - prints help info
 * @args: argument list
 * Return: 1
 */
int lsh_help(char **args)
{
	int i;

	if (args == NULL)
		return (0);


	printf("Type man followed by name of command, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * lsh_exit - closes the shell
 * @args: argument
 * Return: 0
 */
int lsh_exit(char **args)
{
	if (args == NULL)
		return (0);
	else
		return (1);
}

/**
 * lsh_cd - navating/changing to directories
 * @args: list of 2 arguments
 * Return: args[1] which is directory
 */
int lsh_cd(char **args)
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
