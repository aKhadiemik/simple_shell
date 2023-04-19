#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LEN 512
#define MAX_TOKENS 32

void execmd(char **argv);
int get_input(char *input_str, char **tokens, int *num_tokens);
char *get_location(char *command);

#endif /* MAIN_H */
