#include "main.h"

/**
 * is_interactive - checks mode of shell
 *
 * Return: 1 if true, 0 if false
 */

int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
