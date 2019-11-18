#include "simple_shell.h"
int main()
{
	char *prompt, *arguments, **argum;
	pid_t child_process;
	int *status_fork = NULL, sizeArgum, cnt = 0;

	do {
		prompt = _prompt(isatty(STDIN_FILENO));
		sizeArgum = countSpace(prompt);
		argum = malloc(sizeof(char*) * ++sizeArgum);

		if (argum == NULL)
			perror("./hsh");

		child_process = fork();

		if (child_process == 0)
		{
			arguments = strtok(prompt, " \t\n\r");

			while(arguments != NULL)
			{
				argum[cnt++] = arguments;
				arguments = strtok(NULL, " \t\n\r");
			}

			argum[cnt] = NULL;
			_execve(argum);
			exit(0);
		}

		if (child_process > 0)
		{
			wait(status_fork);

			if (isatty(STDIN_FILENO) == 0)
				return(0);
		}

		free(argum);

	} while (1);

	return (0);
}
