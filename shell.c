#include "holberton.h"
/**
 * main - execve example
 * @argc: Number of arguments
 * @argv: array of arguments
 * @env: arraoy of pointer pointing to env variables
 * Return: Always 0 or 1 if it fails.
 */
int main(int argc, char *argv[], char **env)
{
	ssize_t lenget;
	size_t n;
	int tru = 1, flag = 0, counte = 0;
	char *lineptr = NULL, *path = NULL, *copy = NULL;
	char **patht, **strt;

	while (tru)
	{
		counte++;
		signal(SIGINT, sigchld_handler);

		if(isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		lenget = getline(&lineptr, &n, stdin);
		if (lenget == -1)
		{
			if (argc != 1)
				perror(argv[0]);
			return (1);
		}
		if (*lineptr != '\n')
		{
			strt = tokenizeline(lineptr, env);
			if (_strcmp(strt[0], "env") != 0)
			{
				path = getpath(env);
				patht = tokenpath(path, copy);
				flag = _stat(strt, patht);
				/*printf("%s", strt[1]);*/
				run_process(strt, argv[0], copy, flag, counte, env);
			} else
			{
				free(strt);
			}
		}
	}
	return (0);
}
/**
 * sigchld_handler - function to do something to replace ctrl c
 * @sig: number of Signal
 * Return: Do not return
 */
void sigchld_handler(int sig)
{
	(void)sig;
	write(STDIN_FILENO, "\n$ ", 3);
}
/**
 * error - funcntion to print error
 * @argv: nameexe
 * @errortype: id for error
 * @counte: how many times run shell
 * @argu: first argu
 * Return: Do not return
 */
void error(char *argv, int errortype, int counte, char *argu)
{
	char *number = convert(counte, 10);

	printerr(argv), printerr(": ");
	if (errortype == 0)
	{
		printerr(number), printerr(": "), printerr(argu);
		write(STDERR_FILENO, ": not found\n", 12);
	}
	else
	{
		printerr(number), printerr(": "),
			printerr(argu), printerr(": ");
		perror(NULL);
	}
}
/**
 * printerr - funcntion to print message for errors
 * @str: nameexe
 * Return: length
 */
int printerr(char *str)
{
	int i = _strlen(str);

	write(STDERR_FILENO, str, i);
	return (i);
}
/**
 * convert - funcntion to convert int in char
 * @num: num to convert
 * @base: base
 * Return: pointer for print
 */
char *convert(unsigned int num, int base)
{
	static const char rep[] = "0123456789ABCDEF";
	static char buffer[11];
	char *ptr;

	ptr = &buffer[10];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}
