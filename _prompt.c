#include "simple_shell.h"

char *_prompt(int status_iss, char *fileName)
{
	char *get_promtp;
	int len;
	size_t size_buffer = 0;

	do {
		if (status_iss)
			_putchar('$');
		len = getline(&get_promtp, &size_buffer, stdin);
		exitValidation(get_promtp);

		if (len == EOF)
		{
			_putchar('\n');
			exit(0);
		}

		if (len == -1)
			perror(fileName);

	} while (len == 1 || len == 0);

	return (get_promtp);
}

int countSpace(char *prompt)
{
	int cnt = 0, size = 1;

	while (*(prompt + cnt))
	{
		if (*(prompt + cnt) == 32)
			size++;
		cnt++;
	}

	return (size);
}

void exitValidation(char *prompt)
{
	char *_exit = "exit\n";

	if (_strcmp(_exit, prompt) == 0)
		exit(0);
}
