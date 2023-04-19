/**
* main - entry point for the shell program
*
* @ac: number of arguments passed to the program
* @argv: array of string arguments passed to the program
*
* Return: 0 on successful completion
*/

#include "main.h"

int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	char prompt[] = "$ ";
	char input_str[MAX_INPUT_LEN];
	int num_tokens = 0, i;
	char *tokens[MAX_TOKENS] = {NULL};

	/* Loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		get_input(input_str, tokens, &num_tokens);
		execmd(tokens);

		for (i = 0; i < num_tokens; i++)
		{
			if (tokens[i] != NULL)
			{
				free(tokens[i]);
				tokens[i] = NULL;
			}
		}
		num_tokens = 0;
	}

	return (0);
}
