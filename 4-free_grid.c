#include "holberton.h"
/**
 * free_doubpoint - Functions for concatenate two strings
 * @point: pointer to array of pointers
 *
 * Return: do not return.
 */

void free_doubpoint(char **point)
{
	int count = 0;

	while (count < 64)
	{
		free(point[count]);
		count = count + 1;

	}
	free(point);
}
