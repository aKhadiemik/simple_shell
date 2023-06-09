#include "main.h"
/**
 *get_location - gets location of a command
 *@command: cmd passed by user
 *Return: Null
 */
char *get_location(char *command)
{
	char *path = getenv("PATH"), *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat st;

	if (path && (strcmp(command, "exit") != 0))
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &st) == 0 && S_ISREG(st.st_mode))
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &st) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
