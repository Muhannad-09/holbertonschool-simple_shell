# holbertonschool-simple_shell

![Shell Screenshot](https://github.com/Muhannad-09/holbertonschool-simple_shell/blob/main/shell.jpeg?raw=true)
________________________________________________________________________________________________________________
<h1 align="center">🌀 simple_shell</h1>
<p align="center"><em>A custom UNIX command-line interpreter built from scratch in C</em></p>

---

## 🚀 Overview

This project is a **minimalist clone of the Unix shell**, developed as part of the ALX/Holberton low-level programming curriculum.  
It interprets user input, executes built-in and external commands, manages the environment, and handles process control — all using low-level syscalls.

> Think of it as building your own `bash`, one syscall at a time. 🧠⚙️

---

## ✨ Features

✅ Interactive and non-interactive modes  
✅ Command execution via `fork` and `execve`  
✅ Full PATH resolution  
✅ Built-ins: `exit`, `env`, `cd`, `alias`, `help`, `history`, `setenv`, `unsetenv`  
✅ Variable replacement: `$?`, `$$`, `$VARIABLE`  
✅ Logical command chaining: `&&`, `||`, `;`  
✅ Command history (persisted to a file)  
✅ Environment variable manipulation  
✅ Signal handling (`Ctrl+C`)  
✅ Full memory management (valgrind-verified)

---

## 🔧 How to Use

### 🔹 Compile

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
🔹 Run
Interactive mode:
bash
نسخ
تحرير
./hsh
$ ls -la
$ cd ..
$ exit
Non-interactive mode:
bash
نسخ
تحرير
echo "ls -l" | ./hsh
💻 Example Built-in Commands
bash
نسخ
تحرير
$ env
$ setenv EDITOR vim
$ unsetenv EDITOR
$ alias ll='ls -la'
$ history
$ help
$ cd /usr
$ exit
📂 File Breakdown

File	Description
main.c	Entry point — detects mode, passes control to shell loop
shell.c	Core logic: prompt, command parsing, execution
parser.c	Validates executable path and command lookup
builtins.c	Built-in commands like exit, cd, help
builtins2.c	Extended built-ins like alias, history
env.c / environ.c	Custom environment variable management
input.c	User input handling with getline
vars.c	Variable replacement engine ($?, $PATH, etc.)
history.c	Command history management and storage
utils.c	Helper string & character utilities
tokenizer.c	Input tokenization
info.c	Memory and struct management
list.c, list2.c	Singly linked list utilities
shell.h	Global definitions, prototypes, macros
man_1_simple_shell	Manual page for the shell
📘 Manual Page
To view usage via the shell’s man page:

bash
نسخ
تحرير
man ./man_1_simple_shell
🧠 Design Philosophy
This shell avoids all use of high-level wrappers like system() and instead:

Uses fork() + execve() for process control

Manages memory with malloc, realloc, and free

Parses commands manually via custom string/token functions

Implements its own environment logic using linked lists

We didn’t build a shell on top of Linux — we built a shell inside it.

⚡ Advanced Capabilities
Handles multiple chained commands: ls && echo done

Supports custom aliases: alias l='ls -CF'

Maintains persistent command history

Ignores whitespace and comments gracefully

Replaces shell variables with real-time values

🧪 Testing & Debugging
Validated with custom test scripts and manual cases

Leak-checked with valgrind --leak-check=full

Built without system() or other banned functions

Edge cases handled: whitespace, empty input, invalid paths

👨‍💻 Authors

Name	GitHub
Muhannad	@Muhannad-09
Abdulaziz @abdulaziz-sale1
See AUTHORS file for contributors list.



<h3 align="center">🛠️ Code it. 🧠 Understand it. 🚀 Master it.</h3> ```
