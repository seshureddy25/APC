# Arbitrary Precision Calculator (APC)

## Overview
The Arbitrary Precision Calculator (APC) is a C-based application designed to perform arithmetic operations on large integers that exceed the storage limits of standard C data types such as `int` and `long`.

It uses **Doubly Linked Lists** to store and process individual digits, allowing calculations on numbers of arbitrary length.

## Features
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`x`)
- Division (`/`)
- Supports positive and negative integers.
- Handles large numbers without integer overflow.
- Validates command-line arguments.
- Handles invalid operators and division by zero.

## Technologies Used
- C Programming
- Data Structures
- Linked Lists
- Pointers
- Dynamic Memory Allocation
- Command-Line Arguments

## Project Structure

```text
APC/
│
├── main.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── common.h
└── README.md
```

*Note: Adjust the file names according to your actual project structure.*

## Compilation

Compile the project using GCC:

```bash
gcc *.c -o APC.out
```

## Execution

```bash
./APC.out operand1 operator operand2
```

## Examples

**Addition**
```bash
./APC.out 123456789123456789 + 987654321987654321
```

**Subtraction**
```bash
./APC.out 987654321987654321 - 123456789123456789
```

**Multiplication**
```bash
./APC.out 123456789 * 987654321
```

**Division**
```bash
./APC.out 987654321 / 123
```

## Concepts Learned
- Implementing arithmetic
