# Simple Calculator

A simple command-line calculator written in C.

## Description

The program prints a welcome line, displays a menu, and repeats it in a loop
until the user quits with option 0. It performs basic arithmetic operations.

## Menu

* 1) Add
* 2) Subtract
* 3) Multiply
* 4) Divide
* 0) Quit

## Behavior

* Addition, subtraction and multiplication use integers.
* Division uses decimals (example: 10 / 4 = 2.5).
* Dividing by zero prints: Error: division by zero
* An invalid menu choice prints: Invalid choice
* Quitting prints: Bye!

## Compilation

gcc -Wall -Werror -Wextra -pedantic calculator.c -o calculator

## Usage

./calculator

## Author

Zaslse
