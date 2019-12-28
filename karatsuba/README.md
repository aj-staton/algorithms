# Project 3
The third project for the Introduction to Data Structures and Algorithms at the University of South Carolina--Columbia. This was taught by Dr. Jason O'Kane in the Fall of 2019.

See the [project description](https://cse.sc.edu/~jokane/teaching/350/project3.pdf) for more information on the assignment.

## Multiplying Really Big Numbers
Your favorite variable type might not store a number big enough to represent the product of two numbers. A normal, signed, four-byte integer has limits of 01111111 11111111 11111111 11111111 = 2,147,483,647. How do we multiply numbers larger? Use the 'long' datatype? What happens when the 'long' type's physical limits are reached? 
This program multiplies these massive numbers. There are two approaches used to compute the product:
* a brute-force multiplication algorithm (taught in elementary school)
* the Karatsuba algorithm

## Usage
```bash
$ g++ - Wall austinstaton_project3.cpp -o [youroutput]
$ ./[youroutput] < input1.in
```
This program reads from standard input. So, if no input file is redirected, type an orignal cryptarithmetic puzzle to solve after execution. This input must be in the format of:
   [addend]+[addend]=[sum] (e.g. send+more=money). This project focused on the algorithmic problem-solving, rather than bounds checking and error detection.
   
### Limitations
The project is not fully complete. In the subtraction of two vectors, the minutend vector naively reduces the next signficant digit to "borrow" a value, even if that digit is 0. This can create errors in the Karatsuba Algorithm.
