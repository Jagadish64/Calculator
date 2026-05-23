# Modern Calculator

A simple command-line calculator written in C with support for arithmetic operations, percentage, power, square root, and trigonometric functions.

## Features

- Addition, subtraction, multiplication, division
- Percentage (modulus) and result percentage output
- Power and square root functions
- Sine, cosine, tangent in degrees
- Memory support for recall, add/subtract/multiply/divide, and clear
- Simple text menu-driven interface

## Requirements

- GCC or another C compiler
- Windows command prompt or terminal

## Build

From the project root directory:

```powershell
cd "e:\c\Calculator\Modern Calculator"
gcc -Wall -Wextra main.c -o main.exe
```

## Run

```powershell
.\main.exe
```

## Notes

- The program uses `system("cls")` to clear the screen on Windows.
- Invalid input is handled by clearing the input buffer and prompting again.
- The calculator stores the last result in a global variable for memory operations.
