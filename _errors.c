#include "simple_shell.h"
/**
 * showError - display de errors
 * @arg: arguments
 * @fileName: executable file name
 *
 * Return: nothing
 */
void showError(char **arg, char *fileName)
{
	int cntArg = countArguments(arg);
	char *msj, *cntArgP;
	int lenErr, lenMsj;

	lenMsj = lengthArray(fileName) + lengthArray(arg[0]) +
		lengthArray("not found\n") + 7;

	cntArgP = malloc(sizeof(int));

	if (cntArgP == NULL)
		perror(fileName);

	sprintf(cntArgP, "%d", cntArg);

	msj = malloc(sizeof(char) * lenMsj);

	if (msj == NULL)
		perror(fileName);

	_strcpy(msj, fileName);
	_strcat(msj, ": ");
	_strcat(msj, cntArgP);
	_strcat(msj, ": ");
	_strcat(msj, arg[0]);
	_strcat(msj, ": ");
	_strcat(msj, "not found\n");
	msj[lenMsj + 1] = '\0';

	lenErr = lengthArray(msj);

	write(STDERR_FILENO, msj, lenErr);
	exit(0);
}
/**
 * countArguments - count the arguments send
 * @arg: arguments
 *
 * Return: counter
 */
int countArguments(char **arg)
{
	int cnt = 0;

	while (arg[cnt] != NULL)
		cnt++;

	return (cnt);
}
