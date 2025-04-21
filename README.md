<p align="center">
  <img src="https://img.shields.io/badge/Simple_Shell-_Holberton-blue?style=for-the-badge&logo=gnu-bash" alt="Simple Shell">
  <br><br>
  <img src="https://media.giphy.com/media/WoWm8YzFQJg5i/giphy.gif" width="300">
</p>

<h1 align="center">🚀 simple_shell</h1>


## 🛠️ Hardcore Features

- 🔥 Execute commands interactively and non-interactively.
- 🔗 Command chaining: `&&`, `||`, `;`.
- 🧬 Built-ins: `exit`, `env`, `cd`, `alias`, `setenv`, `unsetenv`, `history`, `help`.
- 🧠 Variable replacement (`$?`, `$$`, `$VARIABLE`).
- 🌎 Complete environment variable handling.
- 📜 Persistent command history management.
- 🦾 Bulletproof error handling and memory management.
- 🚦 Signal handling (Ctrl+C interrupts).
- ⚙️ No `system()` calls—pure `fork()`, `execve()`.

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





🚧 Project Structure 

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
