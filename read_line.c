#include "shell.h"

/**
 * read_line - reads line using stdin
 * also allocate buffer
 * Return: readed line
 */
char *read_line(void)
{
/* defining get line using */
#ifdef LSH_USE_STD_GETLINE
	char *line = NULL;
	ssizez_t bufsize = 0;

	getline(&line, &bufsize, stdin);

	return (line);
#else
#define LSH_RL_BUFSIZE 1024
	int bufsize = LSH_RL_BUFSIZE;
	int pos = 0;
	char *buf = malloc(sizeof(char) * bufsize);
	int c;

	if (!buf)
	{
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		} else if (c == '\n')
		{
			buf[pos] = '\0';
			return (buf);
		} else
		{
			buf[pos] = c;
		}
		pos++;

		if (pos >= bufsize)
		{
			bufsize += bufsize;
			buf = realloc(buf, bufsize);
			if (!buf)
			{
				fprintf(stderr, "memory allocation error");
				exit(EXIT_FAILURE);
			}
		}

	}
#endif

}
