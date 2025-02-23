# simple_shell
Simple Shell Implementation in C
Overview
This project is a basic implementation of a Unix-like shell in C. It provides a command-line interface where users can execute commands, manage processes, and perform simple file operations.

Features
Command Execution: Supports execution of basic Unix commands.
Process Management: Handles foreground and background processes.
Built-in Commands: Includes built-in commands like cd, exit, and help.
Piping and Redirection: Basic support for command piping and input/output redirection.
Usage
Compile the Shell: Use a C compiler like gcc to compile the shell program.

gcc -o myshell myshell.c
Run the Shell: Execute the compiled binary to start the shell.

./myshell
Execute Commands: Enter commands at the prompt to execute them.
Example

$ ./myshell
myshell> ls
myshell> echo "Hello, World!"
myshell> exit
