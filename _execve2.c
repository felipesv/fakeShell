#include "simple_shell.h"
/**
 * _execve2 - execute all the commands
 * @prompt: the command to execute
 * @fileName: executable file name
 *
 * Return: is a void
 */
void _execve2(char *prompt, char *fileName)
{
	char **argum;

	argum = _sortArguments(prompt, fileName);
	checkCd(argum[0], argum[1]);
}
/**
 * _sortArguments - sort arguments
 * @prompt: the command to execute
 * @fileName: executable file name
 *
 * Return: **pointer
 */
char **_sortArguments(char *prompt, char *fileName)
{
	char *arguments, **argum;
	int cnt = 0, sizeArgum;

	sizeArgum = countSpace(prompt);
	argum = malloc(sizeof(char *) * ++sizeArgum);
	if (argum == NULL)
		perror(fileName);
	arguments = strtok(prompt, " \t\n\r");
	while (arguments != NULL)
	{
		argum[cnt++] = arguments;
		arguments = strtok(NULL, " \t\n\r");
	}
	argum[cnt] = NULL;
	return (argum);
}
