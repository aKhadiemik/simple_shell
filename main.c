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
	char prompt[] = "$ ", *tokens[MAX_TOKENS] = {NULL}, input_str[MAX_INPUT_LEN];
	char **tokens_copy;
	int num_tokens = 0;

	/* Loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		get_input(input_str, tokens, &num_tokens);

		tokens_copy = malloc((num_tokens + 1) * sizeof(char *));
		if (tokens_copy == NULL)
		{
			fprintf(stderr, "Error: failed to allocate memory for tokens\n");
			return (-1);
		}
		memcpy(tokens_copy, tokens, (num_tokens + 1) * sizeof(char *));
		parse_command(tokens_copy, num_tokens);

		num_tokens = 0;
		free(tokens_copy);
		tokens_copy = NULL;
	}

	return (0);
}
