<p align="center">
  <img src="https://img.shields.io/badge/Simple_Shell-_Holberton-blue?style=for-the-badge&logo=gnu-bash" alt="Simple Shell">
  <br><br>
  <img src="https://media.giphy.com/media/WoWm8YzFQJg5i/giphy.gif" width="300">
</p>

<h1 align="center">🚀 simple_shell</h1>


## 📖 Description

simple_shell is a custom Unix command interpreter implementing basic features of /bin/sh. It supports both interactive and non-interactive modes, built-in commands, variable expansion, command chaining, and robust memory and signal handling without using the system() call.

## 🎯 Learning Objectives

By the end of this project, you will be able to:

Unix History & Design

Explain who designed and implemented the original Unix operating system.

Identify who wrote the first version of the UNIX shell.

Describe the invention of the B programming language (predecessor to C).

Detail who Ken Thompson is and his contributions.

Shell Fundamentals

Explain how a shell works (prompt, parsing, execution).

Define what a PID and a PPID are.

Manipulate the environment of the current process.

Distinguish between a function and a system call.

Create new processes with fork().

List the three prototypes of the main function.

Explain how the shell uses the PATH to locate executables.

Execute another program via the execve system call.

Suspend execution until a child process terminates (wait family).

Handle end-of-file (EOF) conditions.

⚙️ Requirements

Editors: vi, vim, emacs only.

Compilation (Ubuntu 20.04 LTS):

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Coding Style: Betty style enforced (betty-style.pl, betty-doc.pl).

Memory Management: No memory leaks (use valgrind).

File Organization: Max 5 functions per file.

Headers: All header files must be include-guarded.

System Calls: Use only when necessary (avoid system()).

Allowed Functions & System Calls:

String functions (strtok, strlen, etc.)

access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, printf, fprintf, vfprintf, sprintf, putchar, read, readdir, signal, stat, lstat, fstat, wait, waitpid, wait3, wait4, write
---
## ⚙️ How the Shell Works

The `hsh` shell works like `/bin/sh`, supporting both **interactive** and **non-interactive** modes.

---

### 🔹 Example 1: Interactive Mode
```bash
$ ./hsh
$ ls
AUTHORS  builtins.c  env.c  history.c  ...  vars.c
$ exit
```

---

### 🔹 Example 2: Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
AUTHORS  builtins.c  env.c  history.c  ...  vars.c
```

---

### 🔹 Example 3: Input from File
```bash
$ echo "/bin/ls" > test.txt
$ echo "/bin/pwd" >> test.txt
$ echo "echo Hello from hsh" >> test.txt
$ ./hsh < test.txt
AUTHORS  builtins.c  env.c  ...
/root/holbertonschool-simple_shell
Hello from hsh
```

---

### 🔹 Example 4: Built-in `cd`
```bash
$ ./hsh
$ cd /tmp
$ pwd
/tmp
$ exit
```

---

### 🔹 Example 5: Built-in `setenv` and `echo`
```bash
$ ./hsh
$ setenv MY_VAR "Holberton"
$ echo $MY_VAR
Holberton
$ exit
```

---

### 🔹 Example 6: Built-in `alias`
```bash
$ ./hsh
$ alias greet='echo Hello!'
$ greet
Hello!
$ exit
```

---

### 🔹 Example 7: Built-in `history`
```bash
$ ./hsh
$ ls
$ cd /tmp
$ setenv MY_VAR "Holberton"
$ echo $MY_VAR
$ history
1  ls
2  cd /tmp
3  setenv MY_VAR "Holberton"
4  echo $MY_VAR
$ exit
```

---

### 🔹 Example 8: Built-in `help`
```bash
$ ./hsh
$ help
Shell built-in commands:
  cd, exit, env, setenv, unsetenv, alias, history, help
$ exit
```

---

### 🔹 Example 9: Exit the Shell
```bash
$ ./hsh
$ exit
```





## 🚧 Project Structure 

<table>
  <thead>
    <tr>
      <th>File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/shell.c">shell.c</a></td>
      <td>Main shell loop handling command execution.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/parser.c">parser.c</a></td>
      <td>Parses input and resolves command paths.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/input.c">input.c</a></td>
      <td>Manages user input and signal handling.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/info.c">info.c</a></td>
      <td>Maintains shell state and context information.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/utils.c">utils.c</a></td>
      <td>Utility functions for string and character operations.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/tokenizer.c">tokenizer.c</a></td>
      <td>Tokenizes input strings into command arguments.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/vars.c">vars.c</a></td>
      <td>Handles variable replacement and management.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/builtins.c">builtins.c</a></td>
      <td>Implements built-in commands like <code>exit</code>, <code>cd</code>, and <code>help</code>.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/builtins2.c">builtins2.c</a></td>
      <td>Additional built-in commands such as <code>alias</code> and <code>history</code>.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/env.c">env.c</a></td>
      <td>Functions for environment variable operations.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/environ.c">environ.c</a></td>
      <td>Manages the shell's environment variables.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/history.c">history.c</a></td>
      <td>Tracks and manages command history.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/list.c">list.c</a></td>
      <td>Implements singly linked list operations.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/list2.c">list2.c</a></td>
      <td>Additional linked list functionalities.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/realloc.c">realloc.c</a></td>
      <td>Custom memory reallocation functions.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/memory.c">memory.c</a></td>
      <td>Memory management utilities.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/errors.c">errors.c</a></td>
      <td>Error handling and messaging functions.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/errors2.c">errors2.c</a></td>
      <td>Additional error handling functionalities.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/shell.h">shell.h</a></td>
      <td>Header file containing macros, structs, and function prototypes.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/man_1_simple_shell">man_1_simple_shell</a></td>
      <td>Manual page for the simple shell.</td>
    </tr>
    <tr>
      <td><a href="https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/README.md">README.md</a></td>
      <td>Project overview and documentation.</td>
    </tr>
  </tbody>
</table>



## 📖 Manual Page 
```
man ./man_1_simple_shell
```

## 🙌 Authors & Contributors
by:
- Muhannad — @Muhannad-09
- Abdulaziz - @Abdulaziz-Saleh1
<br>
<p align="center"> <strong>💻 Code. 🧠 Learn. 🚀 Conquer.</strong> <br><br> <img src="https://media.giphy.com/media/QTfX9Ejfra3ZmNxh6B/giphy.gif" width="200"> </p> 
