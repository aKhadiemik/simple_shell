#include "main.h"

int parse_command(char **tokens, int num_tokens)
{
	int status, exit_status;
	if (tokens && num_tokens > 0)
	{
		if (strcmp(tokens[0], "exit") == 0)
		{
			status = (tokens[1] != NULL) ? atoi(tokens[1]) : 0;
			exit(status);
		}
		else
		{
			pid_t pid = fork();
			
			if (pid == -1)
			{
				perror("Error:");
			}
			else if (pid == 0)
			{
				execmd(tokens);
			}
			else
			{
				waitpid(pid, &status, 0);
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					if (exit_status != 0)
					{
						printf("Command terminated with exit status %d\n", exit_status);
					}
				}
				else
				{
					printf("Command terminated abnormally\n");
				}
			}
		}
	}
	return (status);
}
