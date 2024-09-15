# Big-Int
Overview
This project implements basic arithmetic operations on large integers (BigInt) in Java. It provides functionality for initialization, addition, subtraction, and multiplication of BigInt values. The project simulates handling integers much larger than Java's primitive data types by breaking them down into 9-digit chunks stored in arrays.

Features-

The project supports the following operations:

Initialization: BigInt arrays are initialized to represent large integers.

Addition: Add two BigInt numbers and store the result.

Subtraction: Subtract one BigInt from another, handling borrow scenarios.

Multiplication: Multiply two BigInt numbers and store the result.

Code Structure-

The project contains three main parts, each representing a different arithmetic operation on BigInt numbers.

1. Addition of BigInt Numbers-
Adds two BigInt numbers and handles overflow by storing carry-over values.
Uses 32-bit unsigned integer operations to ensure large numbers can be added.
2. Subtraction of BigInt Numbers-
Subtracts one BigInt number from another, ensuring the result is non-negative.
If necessary, it uses the 2's complement method to handle cases where borrowing is needed.
3. Multiplication of BigInt Numbers-
Multiplies two BigInt numbers by iterating over each digit and calculating partial products.
Uses shift-and-add technique, similar to how manual multiplication is performed with large numbers.
