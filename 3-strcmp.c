#include "holberton.h"

/**
 * _strcmp - compare two strings
 * @s1: first input word
 * @s2: second input word
 *
 * Return: answer eith copied
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;
	int a2 = 0;
	int a3 = 0;
	int dif;

	/*n = n / 8;*/
	while (s1[a] != '\0')
	{
		a = a + 1;
	}
	while (s2[a2] != '\0')
	{
		a2 = a2 + 1;
	}
	/*if (a2 <= a1)*/
	/*{*/
	while (s1[a3] != '\0')
	{
		dif = s1[a3] - s2[a3];
		if (dif != 0)
		{
			break;
		}
		a3 = a3 + 1;
	}
	return (dif);
}
