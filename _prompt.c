#include "simple_shell.h"

char *_prompt(int status_iss)
{
	char *get_promtp;
	int len;
	size_t size_buffer = 0;

	do {
		if (status_iss)
			_putchar('$');
		len = getline(&get_promtp, &size_buffer, stdin);

		if (len == EOF)
		{
			_putchar('\n');
			exit(0);
		}

		if (len == -1)
			perror("./hsh");

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
