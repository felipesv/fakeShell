#include "simple_shell.h"
int main()
{
	char *prompt;
	pid_t child_process;
	int *status_fork = NULL;

	do {
		prompt = _prompt(isatty(STDIN_FILENO));

		child_process = fork();

		if (child_process == 0)
			_execve(prompt);

		if (child_process > 0)
		{
			wait(status_fork);

			if (isatty(STDIN_FILENO) == 0)
				return(0);
		}

	} while (1);

	return (0);
}
