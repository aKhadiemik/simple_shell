#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_LEN 1024
#define MAX_TOKENS 64
extern char **environ;

#define DELIMS " \n\t"

void execmd(char **argv);
int get_input(char *input_str, char **tokens, int *num_tokens);
char *get_location(char *command);
void exit_shell(int status);
void env_shell(void);
int parse_command(char **tokens, int num_tokens);
int is_interactive(void);
void sigint_handler(int sig);

#endif /* MAIN_H */
