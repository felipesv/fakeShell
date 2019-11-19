#include "simple_shell.h"

void _execve(char *prompt, char *fileName, char **env)
{
	char *arguments, **argum, *path_val, *pathEnv;
	int cnt = 0, sizeArgum;
	struct stat stat_var;

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

	if (stat(argum[0], &stat_var) == 0)
	{
		if(execve(argum[0], argum, NULL) == -1)
			perror(fileName);
	}
	else
	{
		path_val = get_env_value("PATH", env);
		pathEnv = env_split(path_val, argum[0], fileName);

		if(execve(pathEnv, argum, NULL) == -1)
			perror(fileName);
	}

	free(argum);

	exit (0);
}

char *get_env_value(char *nameVar, char **env)
{
	int cnt = 0;
	char *arguments;

	arguments = strtok(env[cnt], "=");

	while (env[cnt])
	{
		if (_strcmp(arguments, nameVar) == 0)
		{
			arguments = strtok(NULL, "\n");
			return(arguments);
		}

		cnt++;
		arguments = strtok(env[cnt], "=");
	}

	return (NULL);
}

char *env_split(char *path_value, char *command, char *fileName)
{
	int lenCommand = 0, lenPath = 0, _mallocsize;
	char *valuePath = strtok(path_value, ":"), *pathDir;
	struct stat stat_var;

	lenCommand = lengthArray(command);
	lenPath = lengthArray(valuePath);
	_mallocsize = lenCommand + lenPath + 1;

	while (valuePath != NULL)
	{
		pathDir = malloc(sizeof(char) * (_mallocsize));
		if (pathDir == NULL)
			perror(fileName);

		strcat(pathDir, valuePath);
		strcat(pathDir, "/");
		strcat(pathDir, command);
		*(pathDir + _mallocsize) = '\0';

		if (stat(pathDir, &stat_var) == 0)
			return (pathDir);

		free(pathDir);

		valuePath = strtok(NULL, ":");
	}

	return (NULL);
}
