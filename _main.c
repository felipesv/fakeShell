#include "simple_shell.h"

int main(int argc, char *argv[], char *env[])
{
	char *prompt;
	pid_t child_process;
	int *status_fork = NULL;
	(void)argc;

	ctrlcValidate();

	do {
		prompt = _prompt(isatty(STDIN_FILENO), argv[0]);
		child_process = fork();

		if (child_process == 0)
			_execve(prompt, argv[0], env);

		if (child_process > 0)
		{
			wait(status_fork);

			if (isatty(STDIN_FILENO) == 0)
				return(0);
		}

	} while (1);

	return (0);
}
