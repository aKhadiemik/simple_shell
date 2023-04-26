#include "main.h"
/**
 * execmd - executes a command using execve
 *
 * @argv: array of pointers to the command and its arguments
 *
 * Return: void
 */

void execmd(char **argv)
{
	char *command = NULL,  *actual_command = NULL;
	char *processed_argv[MAX_TOKENS] = {NULL};
	int num_tokens = 0, i;

	if (argv)
	{
		/* get the command */
		command = argv[0];
		actual_command = get_location(command);

		if (strcmp(command, "env") == 0)
			env_shell();
		while (argv[num_tokens] != NULL)
		{
			if (num_tokens == MAX_TOKENS - 1)
			{
				fprintf(stderr, "Shell: error: too many arguments\n");
				break;
			}
			processed_argv[num_tokens] = strdup(argv[num_tokens]);
			num_tokens++;
		}
		/* execute the command with execve */
		if (execve(actual_command, processed_argv, NULL) == -1)
			perror("Error:");
	}
	if (actual_command)
	{
		free(actual_command);
		actual_command = NULL;
	}
	/* free tokens */
	for (i = 0; i < num_tokens; i++)
	{
		if (processed_argv[i] != NULL)
		{
			free(processed_argv[i]);
			processed_argv[i] = NULL;
		}
	}
}
