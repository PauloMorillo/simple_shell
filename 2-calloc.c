#include "holberton.h"
#include <stdlib.h>
/**
 * _calloc - Function to allocates memory for an array
 * @nmemb: first input array of elements
 * @size: size of elements
 * Return: a pointer or null.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int a = 0;
	char *P;

	if (nmemb == 0 || size == 0)
		return (NULL);
	P = malloc(nmemb * size);
	if (P == NULL)
	{
		free(P);
		return (NULL);
	}
	while (a < nmemb * size)
	{
		P[a] = 0;
		a = a + 1;
	}
	return ((void *)P);
}
