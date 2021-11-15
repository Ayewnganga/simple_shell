#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void start_loop(void);
int call_loop(int argc, char **argv);
char *read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_execute(char **args);
int lsh_exit(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_num_builtins(void);

#endif
