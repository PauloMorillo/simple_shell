#include "holberton.h"
#include <string.h>
/**
 * tokenizeline - function to do tokens from string
 * @lineptr: string from getlne
 * @env: array of pointers pointing to env variables
 * Return: array of pointers with tokens
 */
char **tokenizeline(char *lineptr, char **env)
{
	char *strt = NULL, **toks1 = _calloc(sizeof(char *), 64);
	char *delimi = " \t\r\n\a";
	int count = 0;

	if (toks1 == NULL)
	{
		perror("failed to allocate memory\n");
		exit(1);
	}
	/*printf("comparasion strings\n 1: %s 2:%s", lineptr, copyline);*/
	/*toks = malloc(sizeof(char *) * counttok);*/
	/*if (toks == NULL)*/
	/*exit (1);*/
	strt = strtok(lineptr, delimi);
	for (count = 0; strt != NULL; count++)
	{
		toks1[count] = strt;
		/*printf("%s\n",toks[count]);*/
		strt = strtok(NULL, delimi);
	}
	/*toks1[count] = NULL;*/
	if ((_strcmp(toks1[0], "exit") == 0) && toks1[1] == NULL)
	{
		free(lineptr);
		free(toks1);
		exit(0);
	}
	if (((_strcmp(toks1[0], "env") == 0) && toks1[1] == NULL))
	{
		/*free(lineptr);*/
		_printenv(env);
	}
	return (toks1);
}
