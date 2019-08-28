<p>
<img width="260" height="90" src="https://uploads-ssl.webflow.com/5b0fe6b5acd20859e6fbac66/5b1641a1e46275621a2b436d_Holberton-Logo-final.png" align="right" >
</p>


# Simple Shell
Is a Holberton school group project. The task is to write a simple UNIX command interpreter.

*************************************************************************

# Description
This repo has a simple implementation of the standard command interpreter for the system that receives comands from the standard input or a file.
(Mini Shell) This version has many features that make it similar in some aspects to the standard shell, but it is a simple program to learn its operation. Only some standard shell features have been incorporated.

## More Info
### Output
- Unless specified otherwise, your program __must have the exact same output__ as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)

Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with your program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
******************************************************************************

## List of allowed functions and system calls

* `execve` (man 2 execve)
* `exit`(man 3 exit)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getline` (man 3 getline)
* `malloc` (man 3 malloc)
* `stat` (__xstat) (man 2 stat)

## Compilation
Your shell will be compiled this way:

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
*********************************************************************************

## Examples
### Exercise: super simple shell
Version of a super simple shell that can run commands with their full path, without any argument.
```
julien@ubuntu:~/c/shell$ l
total 140
drwxrwxr-x  2 julien julien 4096 Dec  4 20:55 .
drwxrwxr-x 17 julien julien 4096 Dec  4 13:04 ..
-rw-rw-r--  1 julien julien  249 Dec  4 13:15 env-environ.c
-rw-rw-r--  1 julien julien  231 Dec  4 13:09 env-main.c
-rwxrwxr-x  1 julien julien 8768 Dec  4 19:52 exec
-rw-rw-r--  1 julien julien  302 Dec  4 19:38 exec.c
-rwxrwxr-x  1 julien julien 8760 Dec  4 20:11 fork
-rw-rw-r--  1 julien julien  438 Dec  4 19:57 fork.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:45 mypid
-rw-rw-r--  1 julien julien  179 Dec  4 19:49 pid.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:48 ppid
-rw-rw-r--  1 julien julien  180 Dec  4 13:48 ppid.c
-rwxrwxr-x  1 julien julien 8680 Dec  4 13:44 printenv
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 prompt
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 promptc
-rw-rw-r--  1 julien julien  191 Dec  4 14:17 prompt.c
-rw-rw-r--  1 julien julien  753 Dec  4 20:49 shell.c
-rwxrwxr-x  1 julien julien 8864 Dec  4 20:38 wait
-rw-rw-r--  1 julien julien  441 Dec  4 20:15 wait.c
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic shell.c -o shell
julien@ubuntu:~/c/shell$ ./shell 
#cisfun$ /bin/ls
env-environ.c  exec    fork    mypid  ppid    printenv  promptc   shell    wait
env-main.c     exec.c  fork.c  pid.c  ppid.c  prompt    prompt.c  shell.c  wait.c
#cisfun$ ./ppid
5451
#cisfun$ ./ppid
5451
#cisfun$ ^C
julien@ubuntu:~/c/shell$ 
```
*******************************************************************************
## Authors
[Paulo Morillo](https://github.com/PauloMorillo)

[Edgar Miguel Rodriguez Garcia](https://github.com/Miguelro123)