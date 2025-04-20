# holbertonschool-simple_shell

![Shell Screenshot](https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/shell.jpeg?raw=true)
________________________________________________________________________________________________________________
simple_shell
simple_shell
============

Overview
--------

simple_shell is a simple UNIX command line interpreter built in C. It was developed as part of the Holberton School curriculum to provide a deeper understanding of how shells work at the system level. It mimics the behavior of the standard sh shell and supports both interactive and non-interactive modes.

“The Gates of Shell” - by Spencer Cheng, featuring Julien Barbier

Learning Objectives
-------------------

After completing this project, you should be able to explain
- Who designed and implemented the original UNIX operating system
- Who wrote the first UNIX shell
- Who invented the B programming language (the predecessor of C)
- Who is Ken Thompson
- How a shell works
- What are PID and PPID
- How to manipulate the environment of the current process
- The difference between a function and a system call
- How to create processes
- The three prototypes of main
- How the shell uses PATH to locate programs
- How to execute another program using execve
- How to suspend execution until a child process terminates
- What is EOF (End-of-File)

Requirements
------------

- OS: Ubuntu 20.04 LTS
- Compiler: gcc with the following flags

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

- Coding style: Betty
- No memory leaks
- Maximum 5 functions per file
- All header files must be include-guarded

File Structure
--------------

.
├── main.c              - Entry point
├── shell.c             - Main loop
├── builtins.c          - Built-in commands like exit and env
├── input.c             - Reads user input
├── tokenizer.c         - Parses input into tokens
├── path.c              - Handles PATH resolution
├── env.c               - Environment variable management
├── errors.c            - Error messaging
├── utils.c             - Helper functions
├── memory.c            - Memory allocation helpers
├── shell.h             - Main header
└── README.md

Usage
-----

Interactive Mode

$ ./hsh
($) ls
main.c shell.c hsh
($) exit

Non-Interactive Mode

$ echo "ls" | ./hsh
main.c shell.c hsh

$ cat script.sh | ./hsh
main.c shell.c hsh

Output
------

Your shell must produce the same output as /bin/sh. The only difference is that error messages should show your program’s name (i.e., argv[0]).

Example

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found

Allowed Functions & System Calls
--------------------------------

- All functions from <string.h>
- access, chdir, close, closedir, execve, exit, _exit
- fflush, fork, free, getcwd, getline, getpid, isatty
- kill, malloc, open, opendir, perror, printf
- fprintf, vfprintf, sprintf, putchar, read, readdir
- signal, stat, lstat, fstat, strtok, wait, waitpid
- wait3, wait4, write

Memory Leak Checks
------------------

To test for memory leaks using valgrind

valgrind ./hsh

Authors
-------

- Muhannad-09: https://github.com/Muhannad-09
- abdulaziz-saleh1: https://github.com/abdulaziz-saleh1

Testing Examples
----------------

Interactive

$ ./hsh
($) /bin/ls
main.c shell.c hsh
($) exit

Non-Interactive

$ echo "/bin/ls" | ./hsh
main.c shell.c hsh
