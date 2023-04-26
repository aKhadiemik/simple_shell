#include "main.h"

/**
 * sigint_handler - handles SIGINT
 *
 * @sig: signal
 */

void sigint_handler(int sig __attribute__((unused)))
{
	printf("\n$ ");
	fflush(stdout);
}
