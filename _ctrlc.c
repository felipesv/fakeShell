#include "simple_shell.h"

void ctrlcValidate()
{
	signal(SIGINT, newPrompt);
}

void newPrompt(int _signal)
{
	(void)_signal;
	_putchar('\n');
	_putchar('$');
}
