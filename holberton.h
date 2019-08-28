#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
void *_calloc(unsigned int nmemb, unsigned int size);
void free_doubpoint(char **point);
char *getpath(char **environ);
char **tokenizeline(char *lineptr, char **env);
int _stat(char **toks, char **commnd);
char **tokenpath(char *lineptr, char *copy);
char *_strdup(char *str);
void sigchld_handler(int sig);
int _strcmp(char *s1, char *s2);
void run_process(char **strt, char *nameexe, char *copy, int flag,
int counte, char **env);
int _putchar(char c);
void _puts(char *str);
void _printenv(char **environ);
char *str_concat(char *s1, char *s2);
void error(char *argv, int errortype, int counte, char *argu);
int printerr(char *str);
void printdi(int num);
int _strlen(char *s);
#endif
