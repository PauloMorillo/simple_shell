#include "holberton.h"
#include <string.h>
/**
 * run_process - function to run new process to exe the functions
 * @strt: array of pointers to exe
 * @nameexe: name of exe
 * @copy: ponter copy to free path
 * @flag: flag to know when do free
 * @counte: count how many times sheel works
 * Return: Do not return
 */
void run_process(char **strt, char *nameexe, char *copy, int flag, int counte)
{
pid_t child_pid;
int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(nameexe);
		return;
	}
	if (child_pid == 0)
	{
		if (execve(strt[0], strt, NULL) == -1)
		{
			error(nameexe, 0, counte, strt[0]);
			free(strt);
			exit(1);
		}
		/*free(lineptr);*/
		/*free_doubpoint(strt);*/
		exit(0);
	}
	else
	{
		if (flag == 1)
			free(strt[0]);
		free(strt);
		free(copy);
		/*free(path);*/
		wait(&status);
		/*free_doubpoint(strt);*/
	}
}
