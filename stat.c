#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "holberton.h"
/**
 * _stat - function to find path for a command
 * @strt: array of pointers with command and arguments
 * @toks: array of pointers pointing to directpries from path
 * Return: Return 1 if it is in direcories from path or 0
 */
int _stat(char **strt, char **toks)
{
	unsigned int i = 1;
	struct stat st;
	char *concapath1 = NULL, *concapath2 = NULL;

	/* if (toks[1] == NULL) */
	/* { */
	/*free(toks[0]); */
	/*free(toks); */
	/*return (0); */
	/* } */

	while (toks[i] != NULL)
	{
		concapath1 = str_concat(toks[i], "/");
		concapath2 = str_concat(concapath1, strt[0]);
		/*printf("%s\n", concapath);*/
		if (stat(concapath2, &st) == 0)
		{
			strt[0] = concapath2;
			/*printf("%s\n",strt[0]);*/
			free(concapath1);
			/* free(toks[0]); */
			free(toks[0]);
			free(toks);
			return (1);
			/*break;*/
		}
		free(concapath1);
		free(concapath2);
		i++;
	}
	free(toks[0]);
	free(toks);
	return (0);
}
