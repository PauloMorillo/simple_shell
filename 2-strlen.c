#include "holberton.h"

/**
 * _strlen - return length of a string
 * @s: input pointer
 * Return: length of the strings
 */

int _strlen(char *s)
{
	int a1 = 0;

	while (s[a1] != '\0')
	{
		a1 = a1 + 1;
	}
	return (a1);
}
