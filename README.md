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

## 🧩 Built-ins & Examples


✨ $ cd /usr/bin
✨ $ alias greet='echo Hello, holberton!'
✨ $ greet


✨ $ setenv MY_VAR "Holberton"
✨ $ echo $MY_VAR


✨ $ history
1 cd /usr/bin
2 alias greet='echo Hello, Holberton!'
3 greet
4 setenv MY_VAR "Holberton"
5 echo $MY_VAR

✨ $ help
✨ $ exit

🌟 Quick Demo
Run commands directly:
./hsh
$ ls -la
$ echo "Unix Wizardry"

Pipe commands into the shell:
echo "pwd" | ./hsh

🚧 Project Structure 
```
File | Description
shell.c | Main shell loop handling command execution.
parser.c | Parses input and resolves command paths.
input.c | Manages user input and signal handling.
info.c | Maintains shell state and context information.
utils.c | Utility functions for string and character operations.
tokenizer.c | Tokenizes input strings into command arguments.
vars.c | Handles variable replacement and management.
builtins.c | Implements built-in commands like exit, cd, and help.
builtins2.c | Additional built-in commands such as alias and history.
env.c | Functions for environment variable operations.
environ.c | Manages the shell's environment variables.
history.c | Tracks and manages command history.
list.c | Implements singly linked list operations.
list2.c | Additional linked list functionalities.
realloc.c | Custom memory reallocation functions.
memory.c | Memory management utilities.
errors.c | Error handling and messaging functions.
errors2.c | Additional error handling functionalities.
shell.h | Header file containing macros, structs, and function prototypes.
man_1_simple_shell | Manual page for the simple shell.
README.md | Project overview and documentation.
```

📖 Manual Page (Unix style!)
bash ```
man ./man_1_simple_shell

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
<p align="center"> <strong>💻 Code. 🧠 Learn. 🚀 Conquer.</strong> <br><br> <img src="https://media.giphy.com/media/QTfX9Ejfra3ZmNxh6B/giphy.gif" width="200"> </p> ```
