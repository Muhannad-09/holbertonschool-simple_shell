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
The hsh shell works just like /bin/sh, supporting interactive and non-interactive execution.
🔹 Example 1: Interactive Mode :
📝 Command:
```
$ ls
```
💻 Output:
```
AUTHORS    builtins.c   env.c      errors.c   history.c  info.c   list.c   main.c              memory.c  realloc.c  shell.h     string.c   tokenizer.c  vars.c
README.md  builtins2.c  environ.c  errors2.c  hsh        input.c  list2.c  man_1_simple_shell  parser.c  shell.c    shell.jpeg  string2.c  utils.c
```
🔹 Example 2: Non-interactive Mode : 
📝 Command:
```
echo "/bin/ls" | ./hsh
```
💻 Output:
```
AUTHORS    builtins.c   env.c      errors.c   history.c  info.c   list.c   main.c              memory.c  realloc.c  shell.h     string.c   tokenizer.c  vars.c
README.md  builtins2.c  environ.c  errors2.c  hsh        input.c  list2.c  man_1_simple_shell  parser.c  shell.c    shell.jpeg  string2.c  utils.c
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



📖 Manual Page (Unix style!)
bash 
```
man ./man_1_simple_shell
```
💡 Design Choices (Why it's awesome)
💪 Efficiency: Direct Linux syscalls, avoiding overhead.

🧳 Portability: Runs smoothly on any Unix-based OS.

🔥 Control: No external libs—every byte is yours.

🛡️ Robustness: Meticulously checked with Valgrind—no leaks.

📦 Extensible: Easy to add your custom built-ins and commands.


🎯 Tests & Validation
✅ Valgrind leak-free certification

✅ Manual tests covering edge cases

✅ Holberton compliance (gcc -Wall -Werror -Wextra -pedantic -std=gnu89)

🙌 Authors & Contributors
by:
- Muhannad — @Muhannad-09
- Abdulaziz - @Abdulaziz-Saleh1
<br>
<p align="center"> <strong>💻 Code. 🧠 Learn. 🚀 Conquer.</strong> <br><br> <img src="https://media.giphy.com/media/QTfX9Ejfra3ZmNxh6B/giphy.gif" width="200"> </p> 
