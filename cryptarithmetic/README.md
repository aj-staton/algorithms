# CSCE350 Project 2
Project 2 in course at the University of South Carolina--Columbia, taught by Dr. Jason O'Kane in Fall of 2019.

Solving a _Cryptoartithmetic_ Puzzle using exhausive search. Exhausive search, or "brute force" is the straight-forward, simple way to solve a problem.
Read the [project description](https://cse.sc.edu/~jokane/teaching/350/project2.pdf) for details on the assignment. 

My first thoughts:
 * Test all possible values for each letter (since each letter is assumed to be a single digit value this range is from [0,9]).
 * Check all of these values for its mathematical validity (i.e.--is the expression true). Store each possibility as a C++ 'Map' Key, which points to a boolean true/false.

Unsolicited Advice from Dr. O'Kane:
 * Be careful of your test cases. Test on addends of 2, 3, or 4 test cases regularly. The algorithm should be _slow_, so using addends of greater than five letters is time-consuming.
 
