# Holberton School Simple Shell Project

## SHELL
This project represents a minimal shell implementation, acting as a command language interpreter. It reads commands from a command line string, operating in both interactive and non-interactive modes. It encompasses basic command-line interface functionalities such as command execution, management of environment variables, and display of environment variables. 

## ABOUT

The main function oversees the program flow, encompassing tasks such as reading user input, handling built-in commands (exit and env), creating child processes, and executing commands. It employs custom_getenv and args_writer functions for handling environment variable retrieval and executable path resolution, respectively.

The custom_getenv function retrieves the value of a specified environment variable. It iterates through the environ array, extracting key-value pairs and storing the values in the provided args array.

The _printenv function outputs the contents of environment variables to the console.

The args_writer function locates the executable for a given command. It retrieves the PATH environment variable, iterates through its directories, and checks if the combined path is executable. Upon finding a valid executable, it stores the path in the provided argv array.

The flowchart includes detailed explanations for each step, decision point, and function call, offering a comprehensive insight into the code's logic and structure.

## FILES


### [README.md](./README.md) 
* Description of Simple Shell Repository
### [AUTHORS](./AUTHORS) 
* Contributors of Simple Shell Repository
### [main.h](./main.h) 
* Declarations and Prototypes for Simple Shell Program 
### [shell.c](./shell.c) 
* Main Program for Simple Shell
### [man_1_simple_shell](./man_1_simple_shell) 
* Manual Page of Simple Shell

### Command Execution
* Executes user-entered commands.

### Environment Variable Handling
* Offers functions for retrieving and displaying environment variables.

### Built-in Commands
* Includes built-in commands like exit for shell termination and env for displaying environment variables.

## Features

### Dynamic Path Resolution
* Noteworthy feature allowing dynamic resolution of paths. When a command is entered without an absolute path, the shell searches through directories listed in the PATH environment variable to find the executable file, enabling seamless command execution without specifying full paths.

### Error Handling
* Robust error handling mechanisms are incorporated to gracefully manage various scenarios, such as command not found, memory allocation errors, and fork failures. Informative error messages assist users in understanding encountered issues.

### Clean Input Parsing
* Efficient and clean input parsing. User input is tokenized for separating commands and arguments, ensuring accurate execution and preventing common input-related errors.

### Process Management
* Effective management of child processes spawned for command execution. Utilizes fork system call for creating child processes, waits for their completion using wait system call, and ensures proper handling of process statuses and exit codes.


## Flowchart

<p align="center"><img src="./flowchart.png"></p>



### Compilation

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

## Authors
*	Ilyas Hasanli - [Github]https://github.com/CashlockH/
* Ismayilov Farid - [Github]https://github.com/Fariidismail/
