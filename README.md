# Custom Shell

A simple UNIX-like shell implemented in C.  
This project supports basic built-in commands, running external programs, and a command history feature.  
It was built as a learning project to better understand how shells work internally.

---

## ✨ Features

- Custom shell prompt (default: `my-shell>`).
- Built-in commands:
  - `cd <dir>` → Change directory.
  - `pwd` → Print working directory.
  - `echo <text>` → Print text.
  - `clear` → Clear the terminal.
  - `history` → Show command history.
  - `setenv <var> <value>` → Set environment variable.
  - `unsetenv <var>` → Unset environment variable.
  - `chprompt <string>` → Change shell prompt.
  - `help` → Show available commands.
  - `exit` → Exit the shell.
- Executes external programs using `fork()` and `execvp()`.
- Maintains a command history (up to 100 commands).
- Handles `Ctrl+C` (`SIGINT`) gracefully.
