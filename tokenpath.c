#include "holberton.h"
#include <string.h>
/**
 * tokenpath - function to creates tokens from path directories
 * @path: pointer with variable path
 * @copy: pointer to reserve path an free later
 * Return: Tokens
 */
char **tokenpath(char *path, char *copy)
{
	char *strt = NULL, **toks = _calloc(sizeof(char *), 64);
	int count = 0;

	/*toks = malloc(sizeof(char *) * counttok);*/
	/*if (toks == NULL)*/
	 /*	exit (1);*/
	copy = _strdup(path);
		strt = strtok(copy, "=:");
	/*printf("Esto es el path %s\n y esto es primera pos%s\n", path, strt);*/
		for (count = 0; strt != NULL; count++)
		{
			toks[count] = strt;
			/*printf("%s\n",toks[count]);*/
			strt = strtok(NULL, "=:");
		}
	/*toks[count] = NULL;*/
	/*free(path);*/
	/*free(copy);*/
	return (toks);
}
