#include "shell.h"

/**
 * start_loop - print and loops $
 */
void start_loop(void)
{
	int loop_status;

	do {
		printf("$ ");
		printf("test-shell-loop\n -> shell not yet implemented with functions");
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
