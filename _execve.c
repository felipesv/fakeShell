#include "simple_shell.h"

void _execve(char *arguments[])
{
	if(execve(arguments[0], arguments, NULL) == -1)
	{
		perror("Error");
	}
}
