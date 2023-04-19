#include "main.h"
/**
 * env_shell - prints enviroment of custom shell
 * Return: void
 */

void env_shell(void)
{
	int i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
