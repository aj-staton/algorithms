# CSCE350 Project 2
Project 2 for course at the University of South Carolina--Columbia, taught by Dr. Jason O'Kane in Fall of 2019.

The project solves a _Cryptartithmetic_ Puzzle using exhausive search. Exhausive search, or "brute force" is the straight-forward, simple way to solve a problem.
Read the [project description](https://cse.sc.edu/~jokane/teaching/350/project2.pdf) for details on the assignment. 

## Compilation and Execution
```bash
$ g++ - Wall austinstaton_project2.cpp -o [youroutput]
$ ./[youroutput] < inputALL.in
```
This program reads from standard input. So, if no input file is redirected, type an orignal cryptarithmetic puzzle to solve after execution. This input must be in the format of:
  [addend]+[addend]=[sum]
  Example: send+more=money
This project focused on the algorithmic problem-solving, rather than bounds checking and error detection.
