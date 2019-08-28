#include "holberton.h"
/**
 * getpath - Function to get path and compare path
 * @environ: array of pointers with env variables.
 * Return: Pointer to variable Path
 */
char *getpath(char **environ)
{
	int count = 0;

	if (environ == NULL)
		return (NULL);
	while (environ[count] != NULL)
	{
		if ((environ[count])[0] == 'P' && (environ[count])[1] == 'A' &&
		    (environ[count])[2] == 'T' && (environ[count])[3] == 'H' &&
		    (environ[count])[4] == '=')
		{
			break;
		}
		count++;
	}
	if (environ[count] == NULL)
		return (NULL);
	return (environ[count]);
}
