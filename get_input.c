/**
 * get_input - reads a line of input from stdin and splits it into tokens
 *
 * @input_str: pointer to a buffer to store the input string
 * @tokens: array of pointers to store the tokens
 * @num_tokens: pointer to an integer to store the number of tokens
 *
 * Return: void
 */

#include "main.h"

int get_input(char *input_str, char **tokens, int *num_tokens)
{
	if (fgets(input_str, MAX_INPUT_LEN, stdin) == NULL)
	{
		printf("Exiting shell....\n");
		exit (0);
		return (-1);
	}

	/* Split the string into tokens */
	tokens[*num_tokens] = strtok(input_str, DELIMS);
	while (tokens[*num_tokens] != NULL)
	{
		if (*num_tokens == MAX_TOKENS - 1)
		{
			fprintf(stderr, "Shell: error: too many arguments\n");
			break;
		}
		(*num_tokens)++;
		tokens[*num_tokens] = strtok(NULL, DELIMS);
	}
	tokens[*num_tokens] = NULL;

	return (0);
}
