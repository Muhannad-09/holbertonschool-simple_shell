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



