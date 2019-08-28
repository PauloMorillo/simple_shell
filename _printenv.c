#include "holberton.h"
/**
 * _printenv - function to print environment variables
 * @environ: array with pointers to env variables
 * Return: Do not return
 */
void _printenv(char **environ)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		_puts(environ[count]);
		count++;
	}
}
