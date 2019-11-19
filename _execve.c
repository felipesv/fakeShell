#include "simple_shell.h"

void _execve(char *prompt, char *fileName)
{
	char *arguments, **argum;
	int cnt = 0, sizeArgum;

	sizeArgum = countSpace(prompt);
        argum = malloc(sizeof(char*) * ++sizeArgum);

	if (argum == NULL)
                perror(fileName);

	arguments = strtok(prompt, " \t\n\r");

	while(arguments != NULL)
	{
                argum[cnt++] = arguments;
                arguments = strtok(NULL, " \t\n\r");
	}
	argum[cnt] = NULL;

	if(execve(argum[0], argum, NULL) == -1)
	{
		perror(fileName);
	}

	free(argum);

	exit (0);
}
