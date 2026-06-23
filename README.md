# Arduino 2x1 Multiplexer

Implements a 2x1 MUX in software. Takes three binary inputs 
(D0, D1, S) via Serial Monitor and outputs the selected data 
line on an LED, based on the select line S.

## Hardware used
- Arduino Uno (clone)
- 3 LEDs — D0 indicator (pin 7), D1 indicator (pin 8), output (pin 9)
- Resistors, breadboard, jumper wires

## How it works
Reads three bits from Serial Monitor one at a time. Computes 
output using the boolean MUX expression:
Output = (D0 & (1 - S)) | (D1 & S)
This mirrors the AND-OR gate implementation taught in 
Digital Electronics — connecting theory directly to working code.

## Truth table
S=0 → Output = D0
S=1 → Output = D1

## What I learned
- Managing multi-step Serial input using state variables
- Implementing boolean expressions directly in C
- Connecting Digital Electronics theory (MUX) to embedded code
