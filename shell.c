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
	(void)argc;

	while (tru)
	{
		counte++;
		signal(SIGINT, sigchld_handler);

		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		lenget = getline(&lineptr, &n, stdin);
		if (lenget == EOF)
		{
			free(lineptr);
			exit(2);
		}
		if (*lineptr != '\n')
		{
			strt = tokenizeline(lineptr, env);
			if (_strcmp(strt[0], "env") != 0 && _strcmp(strt[0], "\n") != 0)
			{
				path = getpath(env);
				patht = tokenpath(path, copy);
				flag = _stat(strt, patht);
				run_process(strt, argv[0], copy, flag, counte, env);
			} else
			{
				free(strt); }
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

	printerr(argv), printerr(": ");
	if (errortype == 0)
	{
		printdi(counte), printerr(": "), printerr(argu);
		write(STDERR_FILENO, ": not found\n", 12);
	}
	else
	{
		printdi(counte), printerr(": "),
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
 * printdi - Function to print all the numbers integer or doubles.
 * @num: number
 * Return: digits numbers of an integer or a double
 */
void printdi(int num)
{
	long int numtpr = 0;
	int len = 0;
	long int b = 0;
	long int c = 1;

	numtpr = num;
	if (numtpr < 0)
	{
		_putchar('-');
		numtpr = numtpr * (-1);
		len = 1;
	}
	while (c <= numtpr)
	{
		c = c * 10;
	}
	c = c / 10;
	b = numtpr;
	while (c > 0)
	{
		b = numtpr / c;
		_putchar((b % 10) + '0');
		c = c / 10;
		len = len + 1;
	}
	if (numtpr == 0)
	{
		_putchar(0 + 48);
		len = len + 1;
	}
}
