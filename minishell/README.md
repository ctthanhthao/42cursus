# 🐚 Minishell

A simplified Unix shell written in C. This project is part of the 42 curriculum and aims to recreate a functional command-line shell supporting execution, pipes, redirections, built-ins, and more.

## 📋 Subject Summary

### ✅ Mandatory Requirements

- Display a prompt and wait for user input
- Handle input history (using `readline`)
- Command execution using relative/absolute path or `$PATH`
- Signal handling (with at most one global variable)
- Handle quoting:
  - `'` (single quotes prevent all interpretation)
  - `"` (double quotes allow `$` expansion)
- Redirections:
  - `<`, `>`, `>>`, `<<` (heredoc)
- Pipes (`|`)
- Environment variable expansion (`$VAR`, `$?`)
- Signal handling:
  - `Ctrl-C` → prompt refresh
  - `Ctrl-D` → exit shell
  - `Ctrl-\` → ignored
- Built-in commands:
  - `echo` with `-n`
  - `cd` (absolute or relative path)
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`

### 🌟 Bonus Features

- `&&`, `||` and parentheses for priority
- Wildcard `*` expansion (current working directory)
  
### ❌ Not Supported
- Nested groups (e.g., `(cmd1 && (cmd2 || cmd3))`)
- Heredoc inside groups (e.g., `(cat << EOF)` is not supported)
- Subshells (no separate environment for grouped commands)
- Brace expansion (e.g., `file_{a,b}.txt`)
- Nested globbing (e.g., `dir*/**/*.c`)
- Other stuffs which are not mentioned in subject

## 🛠️ Installation & Usage

### ✅ Requirements
- GNU Make
- Linux (MacOS support is not guaranteed)

### 📦 Build

#### 🔀 Check out the appropriate version

- For **mandatory part**:
  ```bash
  git checkout main
  make
  ```
- For **bonus part**:
  ```bash
  git checkout bonus
  make bonus
  ```
### ▶️ Run
```bash
./minishell
or
./minishell_bonus
```

### Run with valgrind
valgrind -s  --leak-check=full  --show-reachable=yes --show-leak-kinds=definite --error-limit=no  --track-fds=yes  --trace-children=yes  --suppressions=readline.supp  ./minishell

### 🧪Tester
- You can test the functionality of this shell with the following tester:
🔗 [LucasKuhn/minishell_tester](https://github.com/LucasKuhn/minishell_tester)
- I also add some tests for bonus here https://github.com/ctthanhthao/minishell/blob/bonus/minishell_tester/bonus_complex 

## 🚫 Limitations
- No interpretation of unclosed quotes or backslashes (\)
- No semicolon (;) support

# 👥 Contributors
- Andras Marcz
- Thao Chau Thi Thanh
