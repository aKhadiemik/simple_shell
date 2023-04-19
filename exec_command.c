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
	char *command = NULL/*,  *actual_command = NULL */;
	int num_tokens = 0, i;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		/* generate the path to this command before passing it to execve */
		/* actual_command = get_location(command); */

		if (strcmp(command, "exit") == 0)
			exit_shell();

		if (strcmp(command, "env") == 0)
			env_shell();

		while (argv[num_tokens] != NULL)
		{
			if (num_tokens == MAX_TOKENS - 1)
			{
				fprintf(stderr, "Shell: error: too many arguments\n");
				break;
			}
			num_tokens++;
		}

		/* execute the command with execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

	/**
	 * if (actual_command)
	 * {
	 *	free(actual_command);
	 *	actual_command = NULL;
	 * }
	 */

	/* free tokens */
	for (i = 0; i < num_tokens; i++)
	{
		if (argv[i] != NULL)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
	}
}
