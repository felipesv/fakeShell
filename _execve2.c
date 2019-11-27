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
/**
 * _printf_numbers_recursion - Funtion value number.
 * @number: Value int.
 *
 * Return: cnt.
 */
int _printf_numbers_recursion(unsigned int number)
{
	unsigned int new_number = number / 10;
	unsigned int prt_number = number % 10;
	unsigned int cnt = 0;

	if (new_number != 0)
	{
		cnt += _printf_numbers_recursion(new_number);
		cnt++;
		_putchar('0' + prt_number);
	}
	else
	{
		cnt++;
		_putchar('0' + number);
	}

	return (cnt);
}
/**
 * _printf_numbers_recursion - Funtion value number.
 * @number: Value int.
 *
 * Return: cnt.
 */
int _print_numbers_recursion(int number)
{
	int new_number = number / 10;
	int prt_number = number % 10;
	int cnt = 0;

	if (new_number != 0)
	{
		cnt += _print_numbers_recursion(new_number);
		cnt++;
		_putchar('0' + prt_number);
	}
	else
	{
		cnt++;
		_putchar('0' + number);
	}

	return (cnt);
}
