#include "shell.h"

/**
 * start_loop - print and loops $
 */
void start_loop(void)
{
	int loop_status;
	char *line;
	char **args;

	do {
		printf("shell by YourDevLebo \n");
		printf("$ ");
		line = read_line();
		args = lsh_split_line(line);
		loop_status = lsh_execute(args);

		free(line);
		free(args);
	} while (loop_status);
}

/**
 * main - calls the start loop function
 * @argc: argument count
 * @argv: argument vector
 * Return: status code 0 or 1
 */
int main(int argc, char **argv)
{
	start_loop();

	return (EXIT_SUCCESS);
}
