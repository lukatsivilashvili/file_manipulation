# File Copy Utility

This is a simple C program that copies the contents of one file to another using system calls (`open()`, `read()`, and `write()`). The program is divided into multiple source files with a dedicated Makefile for building the project.

## Features

- Copy file contents from one file to another.
- Command-line argument parsing to specify source and destination files.
- Error handling for file operations.
  
## File Structure

- `filecopy.c`: Contains the function that performs the actual file copying.
- `filecopy.h`: Header file that provides the prototype for the `file_copy` function.
- `main.c`: Contains the `main()` function and handles the program flow.
- `parse_args.c`: Handles parsing of command-line arguments using `getopt()`.
- `Makefile`: Automates the build process for the project.

## Compilation

To compile the program, you need to have `gcc` installed.

Use the following command to compile the program:

# Usage
To run the program, use the following command:

```bash
make
```

```bash
./copyfile -s <source_file> -d <destination_file>
```
