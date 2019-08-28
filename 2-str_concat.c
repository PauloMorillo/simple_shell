#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - Functions for concatenate two strings
 * @s1: input size of array to create
 * @s2: Character to put in array
 *
 * Return: Pointer of chars.
 */

char *str_concat(char *s1, char *s2)
{
	char *P;
	int a = 0, b = 0, c = 0, d = 0;

	if (s1 != NULL)
	{
		while (s1[a] != '\0')
		{
			a = a + 1;
		}

	}
	if (s2 != NULL)
	{
		while (s2[b] != '\0')
		{
			b = b + 1;
		}
	}
	P = malloc(a + b + 1);
	if (P == NULL)
	{
		return (NULL);
	}
	while (c < a + b)
	{
		if (c < a)
		{
			P[c] = s1[c];
		}
		else
		{
			P[c] = s2[d];
			d = d + 1;
		}
		c = c + 1;
	}
	P[c] = '\0';
	return (P);
}
