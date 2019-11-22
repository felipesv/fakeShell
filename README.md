# SIMPLE SHELL

A  **Shell**  provides you with an interface to the Unix system. It gathers input from you and executes programs based on that input. When a program finishes executing, it displays that program's output.

Shell is an environment in which we can run our commands, programs, and shell scripts. There are different flavors of a shell, just as there are different flavors of operating systems. Each flavor of shell has its own set of recognized commands and functions.

source [2019]: [https://www.tutorialspoint.com/unix/unix-what-is-shell.htm](https://www.tutorialspoint.com/unix/unix-what-is-shell.htm)


# Files

 - _ctrlc.c 
 - help_cd
 - _prompt.c
 - _read_textfile.c
 - _strcat.c
 - _strcpy.c
 - _execve.c
 - _main.c
 - _putchar.c 
 - simple_shell.h
 - _strcmp.c

## Requirements

-   Allowed editors:  `vi`,  `vim`,  `emacs`
-   All your files will be compiled on Ubuntu 14.04 LTS
-   Your C programs and functions will be compiled with  `gcc 4.8.4`  using the flags  `-Wall`  `-Werror`  `-Wextra`  `and -pedantic`
-   All your files should end with a new line
-   A  `README.md`  file, at the root of the folder of the project is mandatory
-   Your code should use the  `Betty`  style. It will be checked using  [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")  and  [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   No more than 5 functions per file
-   All your header files should be include guarded
-   Use system calls only when you need to ([why?](https://intranet.hbtn.io/rltoken/StgX3y26fwPNV_DqlZLErw "why?"))

### List of allowed functions and system calls

-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

## How to use
**Command:**

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

**Test 1:**

- $ ./hsh
- ($) /bin/ls
- hsh main.c shell.c
- ($)
- ($) exit
- $

**Test 2:**

- $ echo "/bin/ls" | ./hsh
- hsh main.c shell.c test_ls_2
- $
- $ cat test_ls_2
- /bin/ls
- /bin/ls
- $
- $ cat test_ls_2 | ./hsh
- hsh main.c shell.c test_ls_2
- hsh main.c shell.c test_ls_2
- $

## Authors

 - [CARLOS CORTEZ](https://github.com/kael1706)
 - [FELIPE SATIZABAL](https://github.com/felipesv)

## License

Project for:  [Holberton School](https://www.holbertonschool.com/)
