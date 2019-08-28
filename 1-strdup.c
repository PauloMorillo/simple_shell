#include "holberton.h"
#include <stdlib.h>

/**
 * _strdup - Create an array with str
 * @str: input strings to save in another memory space
 *
 *
 * Return: Pointer of chars.
 */

char *_strdup(char *str)
{
	char *P;
	int a = 0;
	int b = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[a] != '\0')
	{
		a = a + 1;
	}
	P = malloc(a + 1);
	if (P == NULL)
		return (NULL);
	while (b <= a)
	{
		P[b] = str[b];
		b = b + 1;
	}
	return (P);
}
